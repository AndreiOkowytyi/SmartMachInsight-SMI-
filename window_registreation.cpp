#include "window_registreation.h"
#include <style.h>

WindowRegistration::WindowRegistration(QWidget *parent) : QMainWindow(parent), p_windowRegistration(new Ui_WindowRegistration) {

    p_windowRegistration->setupUi(this);

    this->p_socket = new Socket;

    style();
    connectSlots();

    this->p_windowRegistration->l_message->close();

    this->p_windowRegistration->l_e_passworld->setEchoMode(QLineEdit::Password);

    this->p_windowRegistration->l_vesion->setText(version);
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

    QObject::connect(this->p_windowRegistration->p_b_entrance, &QPushButton::clicked, this, [this](){

        this->p_workingWindow = new WorkingWindow;
        this->p_workingWindow->show();
        this->close();
    });

    QObject::connect(this->p_windowRegistration->p_b_new_account, &QPushButton::clicked, this, [this](){

        if(!this->p_socket->connectedToServer())  this->p_windowRegistration->l_message->show();;
    });
}
