QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    common_operation.cpp \
    communication_protocol.cpp \
    main.cpp \
    operations.cpp \
    socket.cpp \
    storage_operation.cpp \
    style.cpp \
    window_personal_data.cpp \
    window_registreation.cpp \
    working_window.cpp

HEADERS += \
    common_operation.h \
    communication_protocol.h \
    operations.h \
    socket.h \
    storage_operation.h \
    style.h \
    window_personal_data.h \
    window_registreation.h \
    working_window.h

win32:RC_FILE = icon_.rc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    background.qrc

FORMS += \
    window_personal_data.ui \
    window_registreation.ui \
    working_window.ui
