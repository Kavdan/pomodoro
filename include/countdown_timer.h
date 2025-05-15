#ifndef COUNTDOWN_TIMER_H
#define COUNTDOWN_TIMER_H

#include <QCoreApplication>
#include <QTimer>
#include <QObject>
#include <QDebug>
#include <QLabel>
#include <QPushButton>

#include <string>
#include <iomanip>
#include <sstream>

//QT_BEGIN_NAMESPACE
//namespace Ui { class CountdownTimer; }
//QT_END_NAMESPACE

class CountdownTimer : public QObject {
    Q_OBJECT

public:
    CountdownTimer(int startSeconds,
                   int restSeconds,
                   QLabel *label,
                   QPushButton *button,
                   QObject* parent = nullptr);
    ~CountdownTimer();
    void startTimer();
    void stopTimer();
    QString secondsToTimeString(int totalSeconds);
    bool isRunning;
    bool isResting;

public slots:
    void updateCountdown();

  private:
    QTimer timer;
    QLabel *label;
    QPushButton *button;
    int remainingSeconds;
    int startSeconds;
    int restSeconds;
};


#endif // COUNTDOWN_TIMER_H
