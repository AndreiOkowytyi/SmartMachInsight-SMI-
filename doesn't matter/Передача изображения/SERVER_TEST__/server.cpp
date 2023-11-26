#include "server.h"
#include <QFile>

void Server::startServer() {

    if(this->listen(QHostAddress("192.168.0.107"), 80)) emit goodStart();
    else emit badStart();
    m_Data.clear();
    m_v_count.reserve(3);
}

void Server::incomingConnection(qintptr socketdescriptor) {

    this->p_socket = new QTcpSocket();
    this->p_socket->setSocketDescriptor(socketdescriptor);
    QObject::connect(p_socket, &QTcpSocket::readyRead, this, &Server::slotReadyRead);
    QObject::connect(p_socket, &QTcpSocket::destroyed, this, []() {qDebug() <<"Delete";});
    qDebug() << "new client";
}


void Server::slotReadyRead() {

    this->p_socket = (QTcpSocket*)sender();

    if(this->m_flag_one) {

        m_flag_one = false;
        slotReadyRead_(p_socket);
    }

    else {

    QByteArray temp;
    temp.clear();

    m_next_block_size = 0;

    QDataStream in(this->p_socket);
    in.setVersion(QDataStream::Version::Qt_6_0);

    if(in.status() == QDataStream::Ok) {

        int count = 0;
        bool ok = true;
        while(ok) {
            count++;

            if(count == 10) break;

            qDebug() << "Razmer входящих данніх " << this->p_socket->bytesAvailable();
            qDebug() << "Size neobhodim 0  " << m_next_block_size;
            if(this->m_next_block_size == 0) {

                if(this->p_socket->bytesAvailable() < 2) break;
                in >> this->m_next_block_size;
            }

            qDebug() << "Razmer входящих данніх m_next_block_size " << m_next_block_size;
            if(this->p_socket->bytesAvailable() == this->m_next_block_size) ok = false;
        }

                qDebug() << "чтения файла";
                qDebug() << m_next_block_size;

                in >> temp;

                qDebug() << m_Data.size();

                for(int x = 0; x < temp.size(); x++) this->m_Data.push_back(temp[x]);

                m_as++;

                if(this->m_as == this->m_v_count[1]) deserealization();
        }
    }
}

void Server::slotReadyRead_(QTcpSocket* socket) {

    QDataStream in(socket);
    in.setVersion(QDataStream::Version::Qt_6_0);
    if(in.status() == QDataStream::Ok) {

        for(;;) {

                if(this->m_size_block == 0) {

            if(socket->bytesAvailable() < 2) break;
            in >> this->m_size_block;
                }

                if(socket->bytesAvailable() < this->m_size_block) break;

                QString mes;
                in >> mes;

                rash(mes);

                m_size_block = 0;

                break;
        }
    }
}


void Server::rash(const QString &mes) {

        QString temp;
        int index = 0;

        for(short x = 0; x < mes.size(); ++x) {

        if(mes[x] == '/') {

                this->m_v_count[index] = temp.toInt();
                temp.clear();
                index++;
        }
                else temp.push_back(mes[x]);
        }
        this->m_v_count[index] = temp.toInt();
}


void Server::sendToClient(QString mes) {

    this->m_Data.clear();
    QDataStream out(&m_Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Version::Qt_6_0);
    out << quint16(0) << mes;
    out.device()->seek(0);
    out << quint16(this->m_Data.size() - sizeof(quint16));
    p_socket->write(this->m_Data);
}

void Server::deserealization() {

    QPixmap img;
    img.loadFromData(this->m_Data,"PNG");
    emit pixmap(img);
}

Server::~Server() {this->p_socket->deleteLater();}
