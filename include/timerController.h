#ifndef TIMERCONTROLLER_H
#define TIMERCONTROLLER_H

#include <QObject>
#include "timerModel.h"
#include "timerView.h"
#include <QMediaPlayer>
#include <QAudioOutput>


class TimerController : public QObject {
    Q_OBJECT

public:
    TimerController(TimerModel *model, TimerView *view, QObject *parent = nullptr);

private slots:
    void handleStartStop();
    void handleReset();
    void handleSkip();
    void onTimeUpdated(unsigned seconds);
    void onPhaseChanged(bool resting);
    void onStarted();
    void onStopped();

private:
    TimerModel *model;
    TimerView *view;
    QAudioOutput *audioOutput;
    QMediaPlayer *player;
};

#endif // TIMERCONTROLLER_H
