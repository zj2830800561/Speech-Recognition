#ifndef SPEECH_H
#define SPEECH_H

#include <QObject>
#include <QFile>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QHostInfo>
#include <QFile>
#include <QMessageBox>
#include "http.h"

//获取Token
const QString BaiduTokenUrl = "https://aip.baidubce.com/oauth/2.0/token?grant_type=client_credentials&client_id=%1&client_secret=%2&";
const QString client_id = "bImrLF7B2Lz6alXNfPPTf4tM";
const QString client_secret = "GvpFTKwWNIkA7Y1pgy3KijVPGqWZG410";

//语音识别
const QString speechUrl = "http://vop.baidu.com/server_api?dev_pid=1537&cuid=%1&token=%2";

class speech : public QObject
{
    Q_OBJECT
public:
    explicit speech(QObject *parent = nullptr);
    QString speechIdentify(QString fileName);
    QString getJSONValue(QByteArray ba, QString key);

signals:

private:
    QFile *myFile;
};

#endif // SPEECH_H
