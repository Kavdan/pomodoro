#ifndef APPWINDOW_H
#define APPWINDOW_H

#include <QMainWindow>
#include "timerModel.h"
#include "timerView.h"
#include "timerController.h"

QT_BEGIN_NAMESPACE
namespace Ui { class AppWindow; }
QT_END_NAMESPACE

class AppWindow : public QMainWindow
{
    Q_OBJECT

public:
    AppWindow(QWidget *parent = nullptr);
    ~AppWindow();
    void run(unsigned workSeconds, unsigned restSeconds);

private:
    Ui::AppWindow *ui;
    TimerModel *model;
    TimerView *view;
    TimerController *controller;
    void setupUI();
};
#endif // APPWINDOW_H
