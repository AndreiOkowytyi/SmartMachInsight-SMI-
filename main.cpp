#include <QApplication>

#include "window_registreation.h"


int main(int argc, char *argv[]) {

 QApplication a(argc, argv);

 WindowRegistration windowRegistration;
 windowRegistration.show();

 return a.exec();
}
