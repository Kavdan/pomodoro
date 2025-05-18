#ifndef TIMERPRESENTER_H
#define TIMERPRESENTER_H

//#include "timer.h"
//#include <QLabel>
//#include <QPushButton>
//#include <QObject>
//#include <QString>

//#define START_BUTTON_TXT "start"
//#define STOP_BUTTON_TXT "stop"
//#define PHASE_WORKING_TXT "Работа"
//#define PHASE_RESTING_TXT "Отдых"

//class TimerPresenter : public QObject {
//    Q_OBJECT;

//public:
//    TimerPresenter(Timer *timer,
//                   QLabel *label,
//                   QPushButton *controllButton,
//                   QPushButton *resetButton,
//                   QPushButton *skipButton,
//                   QLabel *phase, QObject *parent = nullptr);

//private slots:
//    void onStarted();
//    void onStopped();
//    void onButtonClicked();
//    void updateTime(const QString &time);
//    void updatePhase(bool phase);
//    void onResetClicked();
//    void onSkipClicked();

//private:
//    Timer *timer;
//    QLabel *label;
//    QPushButton *controllButton;
//    QPushButton *resetButton;
//    QPushButton *skipButton;
//    QLabel *phase;
//};
#include <QString>
#include <iomanip>
#include <sstream>

class TimerPresenter {
public:
    static QString formatTime(unsigned seconds);
    static QString phaseText(bool resting);
};

#endif // TIMERPRESENTER_H
