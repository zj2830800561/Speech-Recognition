#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "audio.h"
#include "speech.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_pressed();

    void on_pushButton_released();

    void on_clear_clicked();

private:
    Ui::MainWindow *ui;
    audio *myAudio;
    speech *mySpeech;
};
#endif // MAINWINDOW_H
