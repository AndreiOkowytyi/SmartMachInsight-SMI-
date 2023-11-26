#include "window_registreation.h"
#include <style.h>

WindowRegistration::WindowRegistration(QWidget *parent) : QMainWindow(parent), p_windowRegistration(new Ui::TaskBoard) {

    p_windowRegistration->setupUi(this);

    this->p_windowRegistration->label_4->close();

    this->p_windowRegistration->lineEdit    ->setStyleSheet(StyleLoginForm::entryField());
    this->p_windowRegistration->lineEdit_2  ->setStyleSheet(StyleLoginForm::entryField());
    this->p_windowRegistration->pushButton  ->setStyleSheet(StyleLoginForm::confirmationButton());
    this->p_windowRegistration->pushButton_2->setStyleSheet(StyleLoginForm::confirmationButton());

    this->p_socket = new Socket;

    this->p_windowRegistration->lineEdit_2->setEchoMode(QLineEdit::Password);

    this->p_windowRegistration->label_6->setText(version);
    this->p_windowRegistration->label_6->setStyleSheet(StyleLoginForm::version());

    /*QObject::connect(this->p_main->pushButton, &QPushButton::clicked, this, [this](){

        if(!this->p_socket->connectedToServer())  this->p_main->label_4->show();;
        this->p_formRegistration = new FormRegistration(this);
        this->p_main->widget->close();
        p_formRegistration->show();
    });*/

    QObject::connect(this->p_windowRegistration->pushButton_2, &QPushButton::clicked, this, [this](){

        if(!this->p_socket->connectedToServer())  this->p_windowRegistration->label_4->show();;
    });
}

WindowRegistration::~WindowRegistration()
{
    delete p_windowRegistration;
    delete p_socket;
}

