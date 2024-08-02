#include "database.h"

QMap<QString, TypeHandler> typeHandlers = {
    { "bool", [](const char*& data, QVariant& value) { value = QVariant(*reinterpret_cast<const bool*>(data)); data += sizeof(bool); } },
    { "int", [](const char*& data, QVariant& value) { value = QVariant(*reinterpret_cast<const int*>(data)); data += sizeof(int); } },
    { "float", [](const char*& data, QVariant& value) { value = QVariant(*reinterpret_cast<const float*>(data)); data += sizeof(float); } },
    { "double", [](const char*& data, QVariant& value) { value = QVariant(*reinterpret_cast<const double*>(data)); data += sizeof(double); } },
    { "short", [](const char*& data, QVariant& value) { value = QVariant(*reinterpret_cast<const short*>(data)); data += sizeof(short); } }
};

void checkAndCreateSettingsFile(const QString &filePath)
{
    QFile file(filePath);
    if (!file.exists()) {
        if (file.open(QIODevice::WriteOnly)) {
            file.write("{}");
            file.close();
            qDebug() << "Settings.json file created.";
        } else {
            qWarning() << "Failed to create Settings.json file.";
        }
    } else {
        qDebug() << "Settings.json file already exists.";
    }
}

//将系统设置写入配置文件
void writeSystemDataToSettings(const QString &filePath, const systemDataSetting &data)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadWrite)) {
        qWarning() << "Failed to open Settings.json file.";
        return;
    }

    QByteArray fileData = file.readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(fileData);
    QJsonObject rootObj = jsonDoc.object();

    // 创建新的系统数据对象
    QJsonObject newSystemData;
    newSystemData["systemName"] = data.systemName;
    newSystemData["localPort"] = data.localPort;
    newSystemData["targetIP"] = data.targetIP;
    newSystemData["targetPort"] = data.targetPort;
    newSystemData["recvDataName"] = QJsonArray::fromStringList(data.recvDataName);
    newSystemData["recvDataType"] = QJsonArray::fromStringList(data.recvDataType);
    newSystemData["sendDataName"] = QJsonArray::fromStringList(data.sendDataName);
    newSystemData["sendDataSource"] = QJsonArray::fromStringList(data.sendDataSource);
    newSystemData["sendData"] = QJsonArray::fromStringList(data.sendData);

    // 添加到JSON数组
    QJsonArray systemDataArray = rootObj["systems"].toArray();
    systemDataArray.append(newSystemData);
    rootObj["systems"] = systemDataArray;

    // 写回文件
    jsonDoc.setObject(rootObj);
    file.resize(0);
    file.write(jsonDoc.toJson());
    file.close();
}

//通过名称删除设置
void deleteSystemDataByName(const QString &filePath, const QString &systemName)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadWrite)) {
        qWarning() << "Failed to open Settings.json file.";
        return;
    }

    QByteArray fileData = file.readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(fileData);
    QJsonObject rootObj = jsonDoc.object();
    QJsonArray systemDataArray = rootObj["systems"].toArray();

    // 查找并删除对应的系统数据
    for (int i = 0; i < systemDataArray.size(); ++i) {
        QJsonObject systemData = systemDataArray[i].toObject();
        if (systemData["systemName"].toString() == systemName) {
            systemDataArray.removeAt(i);
            break;
        }
    }

    rootObj["systems"] = systemDataArray;

    // 写回文件
    jsonDoc.setObject(rootObj);
    file.resize(0);
    file.write(jsonDoc.toJson());
    file.close();
}

//读取系统配置文件
QList<systemDataSetting> readSystemDataFromSettings(const QString &filePath)
{
    QFile file(filePath);
    QList<systemDataSetting> dataList;

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Failed to open Settings.json file at" << filePath;
        return dataList;
    }

    QByteArray fileData = file.readAll();
    qDebug() << "File data:" << fileData;
    fileData.replace("\r\n", "\n");  // 确保使用Unix风格的换行符
    QJsonDocument jsonDoc = QJsonDocument::fromJson(fileData);
    if (jsonDoc.isNull()) {
        qWarning() << "Failed to create JSON doc.";
        return dataList;
    }
    if (!jsonDoc.isObject()) {
        qWarning() << "JSON is not an object.";
        return dataList;
    }

    QJsonObject rootObj = jsonDoc.object();
    QJsonArray systemDataArray = rootObj["systems"].toArray();

    for (const QJsonValue &value : systemDataArray) {
        QJsonObject systemDataObj = value.toObject();
        systemDataSetting data;
        data.systemName = systemDataObj["systemName"].toString();
        data.localPort = systemDataObj["localPort"].toInt();
        data.targetIP = systemDataObj["targetIP"].toString();
        data.targetPort = systemDataObj["targetPort"].toInt();
        data.recvDataName = systemDataObj["recvDataName"].toVariant().toStringList();
        data.recvDataType = systemDataObj["recvDataType"].toVariant().toStringList();
        data.sendDataName = systemDataObj["sendDataName"].toVariant().toStringList();
        data.sendDataSource = systemDataObj["sendDataSource"].toVariant().toStringList();
        data.sendData = systemDataObj["sendData"].toVariant().toStringList();
        dataList.append(data);
    }

    file.close();
    return dataList;
}

//更新数据
void updateSystemDataInSettings(const QString &filePath, const systemDataSetting &data)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadWrite)) {
        qWarning() << "Failed to open Settings.json file.";
        return;
    }

    QByteArray fileData = file.readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(fileData);
    QJsonObject rootObj = jsonDoc.object();
    QJsonArray systemDataArray = rootObj["systems"].toArray();

    // 查找并更新对应的系统数据
    for (int i = 0; i < systemDataArray.size(); ++i) {
        QJsonObject systemData = systemDataArray[i].toObject();
        if (systemData["systemName"].toString() == data.systemName) {
            // 更新系统数据
            systemData["localPort"] = data.localPort;
            systemData["targetIP"] = data.targetIP;
            systemData["targetPort"] = data.targetPort;
            systemData["recvDataName"] = QJsonArray::fromStringList(data.recvDataName);
            systemData["recvDataType"] = QJsonArray::fromStringList(data.recvDataType);
            systemData["sendDataName"] = QJsonArray::fromStringList(data.sendDataName);
            systemData["sendDataSource"] = QJsonArray::fromStringList(data.sendDataSource);
            systemData["sendData"] = QJsonArray::fromStringList(data.sendData);

            systemDataArray[i] = systemData;
            break;
        }
    }

    rootObj["systems"] = systemDataArray;

    // 写回文件
    jsonDoc.setObject(rootObj);
    file.resize(0);
    file.write(jsonDoc.toJson());
    file.close();
}

//查找目标配置
systemDataSetting searchSystemDataSetting(QString systemName)
{
    systemDataSetting targetSetting;

    QString appDirPath = QCoreApplication::applicationDirPath();
    QString settingsFilePath = QDir(appDirPath).filePath("Settings.json");

    QFile file(settingsFilePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Failed to open Settings.json file.";
        return targetSetting;
    }

    QByteArray fileData = file.readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(fileData);
    QJsonObject rootObj = jsonDoc.object();
    QJsonArray systemDataArray = rootObj["systems"].toArray();

    // 查找并更新对应的系统数据
    for (int i = 0; i < systemDataArray.size(); ++i) {
        QJsonObject systemData = systemDataArray[i].toObject();
        if (systemData["systemName"].toString() == systemName) {
            // 更新系统数据
            targetSetting.systemName = systemData["systemName"].toString();
            targetSetting.localPort = systemData["localPort"].toInt();
            targetSetting.targetIP = systemData["targetIP"].toString();
            targetSetting.targetPort = systemData["targetPort"].toInt();
            targetSetting.recvDataName = systemData["recvDataName"].toVariant().toStringList();
            targetSetting.recvDataType = systemData["recvDataType"].toVariant().toStringList();
            targetSetting.sendDataName = systemData["sendDataName"].toVariant().toStringList();
            targetSetting.sendDataSource = systemData["sendDataSource"].toVariant().toStringList();
            targetSetting.sendData = systemData["sendData"].toVariant().toStringList();

            break;
        }
    }

    return targetSetting;

}

//获取对应数据大小
int getTypeSize(const QString &type)
{
    static const QMap<QString, int> typeSizeMap = {
        {"char", sizeof(char)},
        {"short", sizeof(short)},
        {"int", sizeof(int)},
        {"long", sizeof(long)},
        {"float", sizeof(float)},
        {"double", sizeof(double)},
        {"bool", sizeof(bool)},
        {"uchar", sizeof(unsigned char)},
        {"ushort", sizeof(unsigned short)},
        {"uint", sizeof(unsigned int)},
        {"ulong", sizeof(unsigned long)}
    };

    if (typeSizeMap.contains(type))
    {
        return typeSizeMap[type];
    }
    else
    {
        qWarning() << "UnKnown data type: " << type;
        return 0;
    }
}

//计算数据长度
int calculateAlignenSize(const QStringList &dataTypes)
{
    int totalSize = 0;

    for (const QString &type : dataTypes){
        totalSize += getTypeSize(type);
    }

    return totalSize;
}

//返回Json文件地址
QString getSettingsFilePath()
{
    QString appDirPath = QCoreApplication::applicationDirPath();
    QString settingsFilePath = QDir(appDirPath).filePath("Settings.json");

    return settingsFilePath;
}

void PrintSystemSetting(systemDataSetting db)
{
    qDebug() << "systemName " << db.systemName;
    qDebug() << "listenPort " << db.localPort;
    qDebug() << "targetIP   " << db.targetIP;
    qDebug() << "targetPort " << db.targetPort;
    qDebug() << "recvName   " << db.recvDataName;
    qDebug() << "recvType   " << db.recvDataType;
    qDebug() << "sendName   " << db.sendDataName;
    qDebug() << "sendSource " << db.sendDataSource;
    qDebug() << "sendData   " << db.sendData;
}


QList<QVariant> processData(const QByteArray &recvBuffer, const QList<QString> &typeSequence)
{
    QList<QVariant> list;
    QList<QString> valueList;

    const char* data = recvBuffer.data();
    for (const auto& type : typeSequence) {
        QVariant value;
        typeHandlers[type](data, value);
        qDebug() << type << ":" << value.toString();
        list << value;
        valueList << value.toString();
    }
    qDebug() << list;
    qDebug() << valueList;
    return list;
}

bool writeMainStructToFile(const mainStruct &data, const QString &fileName)
{
    QString appDirPath = QCoreApplication::applicationDirPath();
    QString filePath = QDir(appDirPath).filePath(fileName);

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly)) {
        qDebug() << "Failed to open file for writing:" << file.errorString();
        return false;
    }

    QDataStream out(&file);
    out.setByteOrder(QDataStream::LittleEndian);

    out << data.listenPort;
    out << data.targetIP;
    out << data.targetPort;

    file.close();
    return true;
}

mainStruct readMainStructFromFile(const QString &fileName)
{
    QString appDirPath = QCoreApplication::applicationDirPath();
    QString filePath = QDir(appDirPath).filePath(fileName);

    QFile file(filePath);
    mainStruct data = {0, "", 0};

    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open file for reading:" << file.errorString();
        return data;
    }

    QDataStream in(&file);
    in.setByteOrder(QDataStream::LittleEndian);

    in >> data.listenPort;
    in >> data.targetIP;
    in >> data.targetPort;

    file.close();
    return data;
}

void saveJsonToFile(const QJsonDocument &jsonDoc)
{
    QString filePath = getSettingsFilePath();
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qWarning() << "Couldn't open file for writing:" << filePath;
        return;
    }

    QTextStream out(&file);
    out.setCodec("UTF-8");  // 确保使用UTF-8编码
    out.setGenerateByteOrderMark(true);  // 可选：添加UTF-8 BOM
    out << jsonDoc.toJson(QJsonDocument::Indented).replace("\r\n", "\n");  // 确保使用Unix风格的换行符
    file.flush();  // 确保数据写入磁盘
    file.close();

    qDebug() << "JSON data saved to" << filePath;
}
