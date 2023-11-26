#pragma once
#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QImage>
#include <QPixmap>

class Server : public QTcpServer{
    Q_OBJECT
public:
    ~Server();
    void startServer();
    void stopServer();
    QTcpSocket* p_socket = nullptr;

private:
    QByteArray m_Data;
    void sendToClient(QString mes);
    quint16 m_next_block_size = 0;

    quint16 m_size_block = 0;

    void rash(const QString &mes); // Расшифровка первого сообщения.

    void slotReadyRead_(QTcpSocket* socket); // Чтение первого сообщения о пакете.

    bool m_flag_one = true; // Вспомогательная переменная для регулировки.

    short m_as = 0; // Вспомогательная переменная для просчета пакетолв.

    std::vector<long long> m_v_count; // С помощб. вектора мы собираем данные о пакете.

signals:
    void goodStart();
    void badStart();
    void message(QString mes);
    void pixmap(QPixmap image);

public slots:
    void incomingConnection(qintptr socketdescriptor) override;
    void slotReadyRead();
    void deserealization();

};

#endif // SERVER_H
