#pragma once

#ifndef WINDOW_PERSONAL_DATA_H
#define WINDOW_PERSONAL_DATA_H

#include "ui_window_personal_data.h"

/*
Віджет в якому розміщене вікно з особтстою інформацією
користувоча. Також, ця інформація необхідна для відправки
запросів на сервер.
*/

class WindowPersonalData : public QWidget {
    Q_OBJECT
 public:
    WindowPersonalData();
    ~WindowPersonalData();

 private:
    void style();         // Стиль віджетів.
    void toolTipWidget(); // Вспливаючий опис віджетів.
    void connectSlots();  // Метод для об'єднання слотів та сигналів.

    Ui_PersonalData *p_personalData = nullptr;
};

#endif // WINDOW_PERSONAL_DATA_H
