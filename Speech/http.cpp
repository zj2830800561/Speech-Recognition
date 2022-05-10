#include "http.h"

// 完成发送POST请求、接收解析数据的类
Http::Http(QObject *parent) : QObject(parent)
{

}

bool Http::POST(QString Url, QMap<QString, QString> header, QByteArray requestData, QByteArray &replyData)
{
    // 发送请求的对象->发送request
    QNetworkAccessManager manager;
    // 请求对象
    QNetworkRequest request;

    request.setUrl(Url);
    // 迭代器
    QMapIterator<QString, QString> it(header);
    while (it.hasNext()) {
        // 遍历header
        it.next();
        // 添加header
        request.setRawHeader(it.key().toLatin1(), it.value().toLatin1());
    }

    // 发送POST请求
    QNetworkReply *reply = manager.post(request, requestData);

    // 循环事件
    QEventLoop loop;

    // 一旦服务器返回数据，reply会发出finsh信号
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);

    // 等待服务器返回数据
    loop.exec();

    if(reply != nullptr && reply->error() == QNetworkReply::NoError)
    {
        // 成功返回数据
        replyData = reply->readAll();
//        qDebug() << replyData;
        return true;
    }else
    {
        qDebug() << "请求失败";
        return false;
    }
}
