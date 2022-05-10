#ifndef HTTP_H
#define HTTP_H

#include <QObject>
#include <QMap>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QEventLoop>

class Http : public QObject
{
    Q_OBJECT
public:
    explicit Http(QObject *parent = nullptr);
    bool POST(QString Url, QMap<QString, QString> header, QByteArray requestData, QByteArray &replyData);


signals:

};

#endif // HTTP_H
