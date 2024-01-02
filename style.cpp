#include <style.h>

// BLOCK StyleLoginForm

QString StyleLoginForm::entryField() {

    return "QLineEdit{"
           "border-radius: 6px;"
           "}";
}

QString StyleLoginForm::confirmationButton() {

    return "QPushButton {"
           "color: white;"
           "border-radius: 1px;"
           "border-left: 2px solid white;"
           "}"
           "QPushButton:hover {"
           "background-color:#323434;"
           "color: white;"
           "border-radius: 3px;"
           "border-left: 2px solid white;"
           "}";
}

QString StyleLoginForm::version() {

    return "QLabel {color: white;};";
}

// BLOCK StyleWorkingWindow

QString StyleWorkingWindow::find() {

    return "QToolButton {"
           "background-color:#b8f8f8;"
           "border-radius: 5px;"
           "image: url(:/background/find_.jpg);"
           "margin: -1px;"
           "}"
           "QToolButton:hover{"
           "image: url(:/background/find_active_.jpg);"
           "margin: -1px;"
           "}";
}

QString StyleWorkingWindow::search() {

    return "QLineEdit {"
           "background-color: white;"
           "border: 1px solid #cbf3f0;"
           "border-radius: 8px;"
           "padding: 2px;"
           "}";
}

QString StyleWorkingWindow::widgetSearch() {

    return "QWidget {"
           "background-color:#626262;"
           "border-radius: 10px;"
           "color: black;"
           "}";
}

QString StyleWorkingWindow::buttonControlPanel() {

    return "QPushButton{"
           "border:none;"
           "color:white;"
           "}"
           "QPushButton:hover {"
           "background-color:#323434;"
           "color: white;"
           "border-radius: 10px;"
           "}";
}

QString StyleWorkingWindow::back() {

    return "QToolButton {"
           "background-color:#cbf3f0;"
           "border-radius: 5px;"
           "image: url(:/background/back_p_.jpg);"
           "margin: -1px;"
           "}"
           "QToolButton:hover{"
           "image: url(:/background/back_a_.jpg);"
           "margin: -1px;"
           "}";
}

QString StyleWorkingWindow::exit() {

    return "QToolButton {"
           "background-color:#cbf3f0;"
           "border-radius: 5px;"
           "image: url(:/background/exit_p_.jpg);"
           "margin: -1px;"
           "}"
           "QToolButton:hover{"
           "image: url(:/background/exit_a_.jpg);"
           "margin: -1px;"
           "}";
}

QString StyleWorkingWindow::plusPosition() {

    return "QToolButton {"
           "background-color:#cbf3f0;"
           "border-radius: 5px;"
           "image: url(:/background/plus_position_p_.jpg);"
           "margin: -1px;"
           "}"
           "QToolButton:hover{"
           "image: url(:/background/plus_position_a_.jpg);"
           "margin: -1px;"
           "}";
}

QString StyleWorkingWindow::scrollArea() {

    return "QScrollArea {"
          "border-radius: 6px;"
          "border: 2px solid black;"
           "}"
           "QScrollBar:vertical {"
           "border: none;;"
           "background: #FDB96F;"
           "width: 4px; "
           "margin: 0px 0px 0px 0px;"
    "}";
}

QString StyleWorkingWindow::storage() {

    return "QWidget {"
           "border-radius: 6px;"
           "border: 2px solid black;"
           "}";
}

QString StyleWorkingWindow::lable() {

    return "QLabel {"
           "color: white;"
           "}";
}

QString StyleWorkingWindow::personalData() {

    return "QToolButton {"
           "background-color:#cbf3f0;"
           "border-radius: 5px;"
           "image: url(:/background/personal_data_p_.jpg);"
           "margin: -1px;"
           "}"
           "QToolButton:hover{"
           "image: url(:/background/personal_data_a_.jpg);"
           "margin: -1px;"
           "}";
}

QString StyleWorkingWindow::update() {

    return "QToolButton {"
           "background-color:#cbf3f0;"
           "border-radius: 5px;"
           "image: url(:/background/update_p_.jpg);"
           "margin: -1px;"
           "}"
           "QToolButton:hover{"
           "image: url(:/background/update_a_.jpg);"
           "margin: -1px;"
           "}";
}

QString StyleWorkingWindow::message() {

    return "QToolButton {"
           "background-color:#cbf3f0;"
           "border-radius: 5px;"
           "image: url(:/background/message_p_.jpg);"
           "margin: -1px;"
           "}"
           "QToolButton:hover{"
           "image: url(:/background/message_a_.jpg);"
           "margin: -1px;"
           "}";
}

QString StyleWorkingWindow::oneLineTable() {

    return "QPushButton{"
           "border:none;"
           "color:black;"
           "background-color:white;"
           "}"
           "QPushButton:hover {"
           "background-color:#FDB96F;"
           "color: black;"
           "}";
}

QString StyleWorkingWindow::secondLineTable() {

    return "QPushButton{"
           "border:none;"
           "color:black;"
           "background-color:#FEE4C2;"
           "}"
           "QPushButton:hover {"
           "background-color:#FDB96F;"
           "color: black;"
           "}";
}

QString StyleWorkingWindow::column() {

    return "QPushButton{"
           "border:none;"
           "color:black;"
           "background-color:white;"
           "}"
           "QPushButton:hover {"
           "background-color:#FDB96F;"
           "border-radius: 10px;"
           "color: black;"
           "}";
}
