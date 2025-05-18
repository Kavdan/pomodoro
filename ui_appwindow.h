/********************************************************************************
** Form generated from reading UI file 'appwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPWINDOW_H
#define UI_APPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AppWindow
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AppWindow)
    {
        if (AppWindow->objectName().isEmpty())
            AppWindow->setObjectName(QString::fromUtf8("AppWindow"));
        AppWindow->resize(800, 600);
        centralwidget = new QWidget(AppWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        AppWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AppWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        AppWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(AppWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        AppWindow->setStatusBar(statusbar);

        retranslateUi(AppWindow);

        QMetaObject::connectSlotsByName(AppWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AppWindow)
    {
        AppWindow->setWindowTitle(QCoreApplication::translate("AppWindow", "AppWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AppWindow: public Ui_AppWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPWINDOW_H
