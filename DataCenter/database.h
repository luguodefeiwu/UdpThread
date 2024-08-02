#ifndef DATABASE_H
#define DATABASE_H

#include <QCoreApplication>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QString>
#include <QStringList>
#include <QDebug>
#include <QDir>
#include <QVariant>
#include <QMap>
#include <functional>
#include <QTableWidgetItem>

using TypeHandler = std::function<void(const char*&, QVariant&)>;

#pragma pack(push)
#pragma pack(1)
struct dataNormal {
    bool flag;
    int numint1;
    int numint2;
    double numdou1;
};
#pragma pack(pop)

struct systemDataSetting{
    QString systemName;
    quint16 localPort;
    QString targetIP;
    quint16 targetPort;
    QStringList recvDataName;
    QStringList recvDataType;
    QStringList sendDataName;
    QStringList sendDataSource;
    QStringList sendData;
};

struct mainStruct{
    quint16 listenPort;
    QString targetIP;
    quint16 targetPort;
};

QString getSettingsFilePath();

void checkAndCreateSettingsFile(const QString &filePath);

void writeSystemDataToSettings(const QString &filePath, const systemDataSetting &data);

void deleteSystemDataByName(const QString &filePath, const QString &systemName);

QList<systemDataSetting> readSystemDataFromSettings(const QString &filePath);

void updateSystemDataInSettings(const QString &filePath, const systemDataSetting &data);

systemDataSetting searchSystemDataSetting(QString systemName);

int getTypeSize(const QString &type);

int calculateAlignenSize(const QStringList &dataTypes);

void PrintSystemSetting(systemDataSetting db);

QList<QVariant> processData(const QByteArray &recvBuffer, const QList<QString>& typeSequence);

bool writeMainStructToFile(const mainStruct &data, const QString &fileName);

mainStruct readMainStructFromFile(const QString &fileName);

void saveJsonToFile(const QJsonDocument &jsonDoc);

#endif // DATABASE_H
