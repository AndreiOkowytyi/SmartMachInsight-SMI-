#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QTcpServer>
#include <QPixmap>
#include <QImage>
#include <vector>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QByteArray m_data = 0;
    QTcpSocket* p_socket = nullptr;
    quint16 m_size_block;
    QByteArray m_image;

    std::vector<int> m_array_count;

    QByteArray m_temp;

    quint32 m_size = 0;

    QPixmap *pointer;

    QTimer *p_timer;

    short index = 0;

    void seralization();
    void sendToServer();

    void sendToServer_();

private slots:
    void slotReadyRead();

};

#endif // MAINWINDOW_H
