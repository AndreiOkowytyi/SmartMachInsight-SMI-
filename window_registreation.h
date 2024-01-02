#pragma once

#ifndef WINDOW_REGISTREATION_H
#define WINDOW_REGISTREATION_H

#include <QMainWindow>

#include "socket.h"
#include "ui_window_registreation.h"
#include "working_window.h"

/*
Віджет форми реєстрації, та входу до аккаунту.
*/

class WindowRegistration : public QMainWindow {
 Q_OBJECT
 public:
    WindowRegistration(QWidget *parent = nullptr);
    ~WindowRegistration();

 private:
    void style();         // Стиль віджетів.
    void toolTipWidget(); // Вспливаючий опис віджетів.
    void connectSlots();  // Метод для об'єднання слотів та сигналів.

    Ui_WindowRegistration *p_windowRegistration = nullptr; // Вікно реєстрації.
    Socket                *p_socket             = nullptr; // Робота із сокетом.
    WorkingWindow         *p_workingWindow      = nullptr; // Робоче вікно.
};

#endif // WINDOW_REGISTREATION_H
