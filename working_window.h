#pragma once

#ifndef WORKING_WINDOW_H
#define WORKING_WINDOW_H

#include "ui_working_window.h"

#include "window_personal_data.h"

/*
Класс для роботи із основним вікном.
*/

class WorkingWindow : public QWidget {
  Q_OBJECT
 public:
  WorkingWindow();
  ~WorkingWindow();

 private:
  void style();         // Стиль віджетів.
  void toolTipWidget(); // Вспливаючий опис віджетів.
  void connectSlots();  // Метод дял об'єднання слотів та сигналів.
  void fillingData();   // Заповнення таблиці результатом запиту.

  Ui_WorkingWindow   *p_workingWindow      = nullptr; // Вказівник для роботи із основних робочим вікном.
  WindowPersonalData *p_windowPersonalData = nullptr; // Вказівник дял роботи із вікном що містить персональні данні.

 public slots:

};

#endif // WORKING_WINDOW_H
