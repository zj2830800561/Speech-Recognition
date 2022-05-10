#ifndef AUDIO_H
#define AUDIO_H

#include <QObject>
#include <QAudioFormat>
#include <QAudioInput>
#include <QAudioDeviceInfo>
#include <QFile>
#include <QMessageBox>

class audio : public QObject
{
    Q_OBJECT
public:
    explicit audio(QObject *parent = nullptr);

    void startAudio(QString fileName);

    void stopAudio();

signals:

private:
//    录音保存的文件
    QFile *myFile;
//    录音对象
    QAudioInput *myAudio;

};

#endif // AUDIO_H
