#pragma once

#ifndef STYLE_H
#define STYLE_H

#include <QString>

class StyleLoginForm { // Стиль форми реєстрування.
 public:
    static QString entryField();         // Стиль поля ввода.
    static QString confirmationButton(); // Стиль кнопки підтверждення.
    static QString version();
};

class StyleWorkingWindow { // Стлиь віджетів основного робочого вікна.
 public:
    static QString find();               // Cтиль для кнопки пошуку.
    static QString search();             // Стиль поля вводу.
    static QString widgetSearch();       // Стиль головних віджетів.
    static QString buttonControlPanel(); // Стиль основних кнопок.
    static QString back();               // Стиль кнопки "назад".
    static QString exit();               // Стиль кнопки "Вихід".
    static QString plusPosition();       // Стиль кнопки "Плюс позиція".
    static QString scrollArea();
    static QString storage();            // Стиль віджета під схему складу.
    static QString lable();
    static QString personalData();       // Стиль віджета "персональні данні".
    static QString update();             // Стиль кнопки "відновити".
    static QString message();            // Стиль кнопки "повідомлення".
    static QString column();             // Стиль кнопок назви столбців таблиці.
    static QString oneLineTable();       // Стиль першого рядка в таблиці.
    static QString secondLineTable();    // Стиль другого рядка в таблиці.
};


#endif // STYLE_H
