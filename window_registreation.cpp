#include "window_registreation.h"
#include "style.h"
#include "communication_protocol.h"

WindowRegistration::WindowRegistration(QWidget *parent) : QMainWindow(parent), p_windowRegistration(new Ui_WindowRegistration) {

    p_windowRegistration->setupUi(this);

    this->p_socket = new Socket;

    style();
    connectSlots();

    this->p_windowRegistration->l_message->close();

    this->p_windowRegistration->l_e_passworld->setEchoMode(QLineEdit::Password);

    this->p_windowRegistration->l_vesion->setText(VERSION_CLIENT);
}

WindowRegistration::~WindowRegistration() {

    delete p_windowRegistration;
    delete p_socket;
    if(p_workingWindow != nullptr) delete p_workingWindow;
}

void WindowRegistration::style() {

    // Стиль для QLineEdit
    this->p_windowRegistration->l_e_login    ->setStyleSheet(StyleLoginForm::entryField());
    this->p_windowRegistration->l_e_passworld  ->setStyleSheet(StyleLoginForm::entryField());

    // Стиль для QPushButton
    this->p_windowRegistration->p_b_entrance  ->setStyleSheet(StyleLoginForm::confirmationButton());
    this->p_windowRegistration->p_b_new_account->setStyleSheet(StyleLoginForm::confirmationButton());

    // Стиль для QLabel
    this->p_windowRegistration->l_vesion->setStyleSheet(StyleLoginForm::version());
}

void WindowRegistration::connectSlots() {

    QObject::connect(this->p_windowRegistration->p_b_entrance,    &QPushButton::clicked, this, &WindowRegistration::entrance);
    QObject::connect(this->p_windowRegistration->p_b_new_account, &QPushButton::clicked, this, &WindowRegistration::newAccaunt);
}

void WindowRegistration::entrance() {

    std::string as("");

    std::string login_passworld_version = this->p_windowRegistration->l_e_login->text().toStdString() + ' ' +
                                          this->p_windowRegistration->l_e_passworld->text().toStdString() + ' ' + VERSION_CLIENT;

    CommunicationProtocol communicationProtocol;

    std::string temp = communicationProtocol.sendingMessages(as, ListOfOperations::Entrance,
            ReadWrite::Read, ImplementingRequestToTheServer::CheckingAccountAndClientVersion,
                                          DataType::Text, login_passworld_version);
    qDebug() << this->p_windowRegistration->l_e_login->text();

    this->p_socket->sendToServer(this->p_windowRegistration->l_e_login->text());

    this->p_workingWindow = new WorkingWindow;
    this->p_workingWindow->show();
    this->close();
}

void WindowRegistration::newAccaunt() {

    if(!this->p_socket->connectedToServer())  this->p_windowRegistration->l_message->show();
}
