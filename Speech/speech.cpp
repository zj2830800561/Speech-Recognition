#include "speech.h"

speech::speech(QObject *parent) : QObject(parent)
{

}

/*
 * 功能：发送录音文件进行语言识别
 * 参数：录音文件路径
 * 返回值：识别出来的文字
*/
QString speech::speechIdentify(QString fileName)
{
    QString accessToken;
//    获取TokenUrl
    QString TokenUrl = QString(BaiduTokenUrl).arg(client_id).arg(client_secret);
//    qDebug() << TokenUrl;

    QMap<QString, QString> header;
    header.insert(QString("Content-Type"), QString("audio/pcm;rate=16000"));

    QByteArray requestData;  //发送的内容
    QByteArray replyData;    //服务器返回的内容

    Http myHttp;
    bool result =  myHttp.POST(TokenUrl, header, requestData, replyData);
    if(result)
    {
        QString key = "access_token";
        accessToken = getJSONValue(replyData, key);
//        qDebug() << "accessToken" << accessToken;
    }
    else
    {
//        this->close();
    }

    // 语音识别
    QString BaiduspeechUrl = QString(speechUrl).arg(QHostInfo::localHostName()).arg(accessToken);

    // 把文件转化为ByteArray
    QFile myFile;
    myFile.setFileName(fileName);
    myFile.open(QIODevice::ReadOnly);
    requestData = myFile.readAll();
    myFile.close();

    result =  myHttp.POST(BaiduspeechUrl, header, requestData, replyData);
    if(result)
    {
        QString key = "result";
        QString text = getJSONValue(replyData, key);
        return text;

    }
    else {
        QMessageBox::warning(NULL, "转化失败", "语音识别失败");
    }

    return "";
}

/*
 * 功能：对服务器返回的JSON数据进行解析
 * 参数1：服务器返回的数据
 * 参数2：需要提取value的key
 * 返回值：识别出来的文字
*/
QString speech::getJSONValue(QByteArray ba, QString key)
{
//    qDebug() << "ba:" << ba;
    QJsonParseError parseError;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(ba, &parseError);
    // 如果转换没有错误
    if(parseError.error == QJsonParseError::NoError)
    {
        // 如果是一个JSON对象
        if(jsonDocument.isObject())
        {
            QJsonObject jsonObj = jsonDocument.object();
            // 如果对象里包含key
            if(jsonObj.contains(key)){
                // 获取想要的结果
                QJsonValue jsonValue = jsonObj.value(key);
                // 如果是字符串=>Token
                if(jsonValue.isString())
                {
                    return jsonValue.toString();
                }
                else if(jsonValue.isArray())
                {
                    // 如果是数组=> 语音识别结果
                    QJsonArray arr = jsonValue.toArray();
                    // 获取第一个识别结果
//                    qDebug() << "arr:" << arr;
                    return arr.at(0).toString();
                }
            }
        }
    }
    return "";
}
