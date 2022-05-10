#include "audio.h"

// 完成音频录制的类
audio::audio(QObject *parent) : QObject(parent)
{

}

//开始录音
void audio::startAudio(QString fileName)
{
    // 录音设备
    QAudioDeviceInfo device= QAudioDeviceInfo::defaultInputDevice();
    // 判断设备有无录音设备：QAudioDeviceInfo
    if(device.isNull())
    {
        // 没有录音设备，弹出提示框
        QMessageBox::warning(NULL, "QAudioDeviceInfo", "缺少录音设备!");
    }else
    {
        // 需要设置参数：QAudioFormat（采样频率、通道数、位深、编码格式）
        QAudioFormat myFormat;
        myFormat.setSampleRate(16000);
        myFormat.setChannelCount(1);
        myFormat.setSampleSize(16);
        myFormat.setCodec("audio/pcm");
        // 判断设备是否支持该格式，不支持则需要切换
        if(!device.isFormatSupported(myFormat))
        {
            myFormat = device.nearestFormat(myFormat);
        }
        // 打开录音文件QFile
        myFile = new QFile();
        myFile->setFileName(fileName);
        myFile->open(QIODevice::WriteOnly);
        // 创建录音对象AudioInput（Format，this）
        myAudio = new QAudioInput(myFormat, this);
        // 开始录音，保存到myFile中
        myAudio->start(myFile);
    }
}

//停止录音
void audio::stopAudio()
{
//    、停止录音
    myAudio->stop();
//    、关闭QFile
    myFile->close();
//    、删除文件指针
    delete myFile;
    myFile = NULL;
}
