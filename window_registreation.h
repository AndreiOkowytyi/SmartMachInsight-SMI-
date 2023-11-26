#pragma once

#ifndef WINDOW_REGISTREATION_H
#define WINDOW_REGISTREATION_H

#include <QMainWindow>

#include "socket.h"
#include "ui_mainwindow.h"

class WindowRegistration : public QMainWindow {
 Q_OBJECT
 public:
    WindowRegistration(QWidget *parent = nullptr);
    ~WindowRegistration();

 private:
    Ui::TaskBoard *p_windowRegistration = nullptr;
    Socket* p_socket                    = nullptr;
};

#endif // WINDOW_REGISTREATION_H
