#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QBuffer>
#include <vector>
#include <thread>

/*

Идея заключаеться в разбитие файла на блоке размеров не более 55000 байт.
После реализуеться отправка информации о файлк тип сообщения/количество блоков/размер файла в сумме.
После, блоки отправляються групами на сервер/клиент, а там собираються.

*/

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    pointer = new QPixmap("C:/CLIENT_TEST/12.png");
    this->ui->label_2->setPixmap(pointer->scaled(this->ui->label_2->width(), this->ui->label_2->height()));

    this->p_socket = new QTcpSocket;
    this->p_timer = new QTimer(this);

    QObject::connect(p_socket, &QTcpSocket::readyRead, this, &MainWindow::slotReadyRead);
    QObject::connect(this->ui->pushButton, &QPushButton::clicked, this, [this]() {

        this->p_socket->connectToHost("192.168.0.107", 80);
    });

    QObject::connect(p_timer,&QTimer::timeout, this, [this]() {

        this->sendToServer();
        index++;
        if(index == this->m_array_count.size()) {

            this->p_timer->stop();
            m_image.clear();
            m_array_count.clear();
            index = 0;
        }
    } );

    QObject::connect(this->ui->pushButton_2, &QPushButton::clicked, this, [this]() {

        std::thread node([this]() {seralization();}); // Сириализацию производим в отдельном потоке.
        node.join();

        sendToServer_();   // Перед отправкой основных данных мы отправляем дпнные о пакете.
        p_timer->start(3); // Каждые 3 милисекунды происходит отправка на сервер.
    });
}

MainWindow::~MainWindow() {

    delete ui;
}

void MainWindow::slotReadyRead() {

    this->p_socket = (QTcpSocket*)sender();
    QDataStream in(this->p_socket);
    in.setVersion(QDataStream::Version::Qt_6_0);
    if(in.status() == QDataStream::Ok) {

        for(;;) {

            if(this->m_size_block == 0) {

                if(this->p_socket->bytesAvailable() < 2) break;
                in >> this->m_size_block;
            }

            if(this->p_socket->bytesAvailable() < this->m_size_block) break;

        QString mes;
        in >> mes;
        m_size_block = 0;
        break;
    }
  }
}


void MainWindow::sendToServer() { // Отправка данных по блокам.

    QByteArray temp;

    long long result = 0;

    auto lambda = [&]() {

        long long result = 0;
        for(short x = 0; x < this->index; ++x) result += this->m_array_count[x];
        return result;
    };

    result = lambda();

    for(int x = 0; x < this->m_array_count[index]; x++) temp.push_back(this->m_image[x + result]);

    this->m_data.clear();
    QDataStream out(&m_data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Version::Qt_6_0);
    out << quint64(0) << temp;
    out.device()->seek(0);
    out << quint64((m_data.size() - sizeof(quint64)));

    p_socket->write(m_data);
}

void MainWindow::sendToServer_() { // отправка данных о пакетах.

    QString mes;

    m_temp.clear();

    mes += "1/" + QString::number(this->m_array_count.size()) + "/" + QString::number(this->m_image.size());

    qDebug() << mes;

    QDataStream out(&m_temp, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Version::Qt_6_0);
    out << quint16(0) << mes;
    out.device()->seek(0);
    out << quint16((m_temp.size() - sizeof(quint16)));

    p_socket->write(m_temp);
}

void MainWindow::seralization() {

    QBuffer buffer(&m_image);
    buffer.open(QIODevice::WriteOnly);
    this->pointer->save(&buffer,"PNG");

    if(m_image.size() > 55000) {

    short count_path = m_image.size() / 55000;

    long long result = count_path * 55000;

    if(result < m_image.size()) count_path++;

    for(int x = 0; x < count_path; x++) {

    if(x != (count_path - 1)) m_array_count.push_back(55000);

    else {

        short result = m_image.size() - ((count_path - 1) * 55000);
        m_array_count.push_back(result);
    }
    }
}
    else m_array_count.push_back(m_image.size());
}
