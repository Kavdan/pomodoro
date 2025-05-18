#ifndef TIMERVIEW_H
#define TIMERVIEW_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>

class TimerView : public QWidget {
    Q_OBJECT

public:
    TimerView(QWidget *parent = nullptr);
    void updateTimeDisplay(const QString &text);
    void updatePhaseDisplay(const QString &text);
    void updateStartStopButton(bool running);

signals:
    void startStopClicked();
    void resetClicked();
    void skipClicked();

private:
    QLabel *timeLabel;
    QLabel *phaseLabel;
    QPushButton *startStopButton;
    QPushButton *resetButton;
    QPushButton *skipButton;
};

#endif // TIMERVIEW_H
