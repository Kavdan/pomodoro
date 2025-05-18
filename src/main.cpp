#include "include/configLoader.h"
#include "include/appwindow.h"
#include <QApplication>
#include <QString>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <iostream>
#include <limits>

#define DEFAULT_WORK_TIME 25*60
#define DEFAULT_REST_TIME 5*60

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QIcon icon(":/icons/pomodoro.ico");
    if (icon.isNull()) {
        qDebug() << "Icon failed to load!";
    } else {
        qDebug() << "Icon loaded successfully!";
    }
    a.setWindowIcon(icon);
    AppWindow w;
    w.resize(300, 400);
    w.setWindowTitle("Pomodoro");

    unsigned workTime = DEFAULT_WORK_TIME;
    unsigned restTime = DEFAULT_REST_TIME;

    ConfigLoader::parseConfig(workTime, restTime);

    w.run(workTime, restTime);
    w.show();
    return a.exec();
}
