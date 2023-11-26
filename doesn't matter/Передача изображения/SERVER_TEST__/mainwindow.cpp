#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    p_server = new Server;
    QObject::connect(this->ui->start, &QPushButton::clicked, this, [this](){

        this->p_server->startServer();
    });
    QObject::connect(p_server, &Server::goodStart, this, [this](){

        this->ui->label->setText("sTART sERVER GOOD");
    });

    QObject::connect(p_server, &Server::badStart, this, [this](){

        this->ui->label->setText("sTART sERVER bad");
    });

    QObject::connect(this->p_server,&Server::message, this, [this](QString mes) {

        this->ui->message_->clear();
        this->ui->message_->setText(mes);
    });

    QObject::connect(this->p_server,&Server::pixmap, this, [this](QPixmap pv) {

        this->ui->label_2->clear();
        this->ui->label_2->setPixmap(pv.scaled(this->ui->label_2->width(), this->ui->label_2->height()));

    });

    QObject::connect(this->ui->pushButton, SIGNAL(clicked()), this->p_server, SLOT(deserealization()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete p_server;
}

