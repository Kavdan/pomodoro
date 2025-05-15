#ifndef APPWINDOW_H
#define APPWINDOW_H

#include <QMainWindow>
#include "timer.h"
#include "timerPresenter.h"

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
    QLabel* timerLabel;
    QPushButton* controlButton;
    QPushButton* resetButton;
    QPushButton* skipButton;
    QLabel *phase;

    Timer* timer;
    TimerPresenter* timerPresenter;
    void setupUI();
};
#endif // APPWINDOW_H
