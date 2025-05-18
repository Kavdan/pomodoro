QT  += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

TARGET = pomodoro

SOURCES += \
    src/configLoader.cpp \
    src/main.cpp \
    src/appwindow.cpp \
    src/timerController.cpp \
    src/timerModel.cpp \
    src/timerPresenter.cpp \
    src/timerView.cpp

HEADERS += \
    include/appwindow.h \
    include/configLoader.h \
    include/timerController.h \
    include/timerModel.h \
    include/timerPresenter.h \
    include/timerView.h

FORMS += \
    ui/appwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

ICON = icons/pomodoro.png

RESOURCES += \
    resources.qrc

DISTFILES += \
    app.desktop \
    icons/pomodoro.png \
    install-icons.sh

QMAKE_POST_LINK += ./install-icons.sh || true

ICON_FILE = icons/pomodoro.png
DESKTOP_FILE = app.desktop

icon.path = /usr/share/icons/hicolor/128x128/apps
icon.files = $$ICON_FILE

desktop.path = /usr/share/applications
desktop.files = $$DESKTOP_FILE

INSTALLS += icon desktop
