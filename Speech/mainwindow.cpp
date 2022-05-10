#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setGeometry(0,0,800,480);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_pressed()
{
//    长按事件：
    myAudio = new audio;
//    1、改变文字
    ui->pushButton->setText("松开识别");
//    2、开始录音
    myAudio->startAudio("/home/ajie/audiotest.pcm");
}

void MainWindow::on_pushButton_released()
{
//    按键释放：
//    、停止录音
    myAudio->stopAudio();
//    、改变文字
    ui->pushButton->setText("正在识别");
//    、开始识别
    mySpeech = new speech(this);
    QString result = mySpeech->speechIdentify("/home/ajie/audiotest.pcm");

    ui->textEdit->setText(result);
    ui->pushButton->setText("按住说话");
}

void MainWindow::on_clear_clicked()
{
    ui->textEdit->clear();
}
