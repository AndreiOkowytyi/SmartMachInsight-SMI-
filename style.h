#pragma once

#ifndef STYLE_H
#define STYLE_H

#include <QString>

class StyleLoginForm {
 public:
    static QString entryField();         // Стиль поля ввода
    static QString confirmationButton(); // Стиль кнопки підтверждення
    static QString version();
};

/*class StyleWorkingWindow {
public:
    static QString iconsNewTask(); // Стиль іконки створення нового завдання.
    static QString setting();
    static QString toolButtonAccount();
    static QString iconTeam();
    static QString iconMessage();
    static QString iconStatistics();
    static QString iconTask();
    static QString arroe();
    static QString arrow_1();
    static QString arrow_2();
    static QString totalNumberTask();
    static QString taskInTheQueue();
    static QString completedTask();
};*/

#endif // STYLE_H
