#include <iostream>
#include "include/timerController.h"
#include "include/timerPresenter.h"

TimerController::TimerController(TimerModel *model, TimerView *view, QObject *parent)
    : QObject(parent),
      model(model),
      view(view),
      player(new QMediaPlayer(this)),
      audioOutput(new QAudioOutput(this)) {

    connect(view, &TimerView::startStopClicked, this, &TimerController::handleStartStop);
    connect(view, &TimerView::resetClicked, this, &TimerController::handleReset);
    connect(view, &TimerView::skipClicked, this, &TimerController::handleSkip);

    connect(model, &TimerModel::timeUpdated, this, &TimerController::onTimeUpdated);
    connect(model, &TimerModel::phaseChanged, this, &TimerController::onPhaseChanged);
    connect(model, &TimerModel::started, this, &TimerController::onStarted);
    connect(model, &TimerModel::stopped, this, &TimerController::onStopped);

    connect(player, &QMediaPlayer::errorOccurred, this, [](QMediaPlayer::Error error, const QString &errorString) {
        std::cerr << "Audio error: " << error << " - " << errorString.toStdString() << std::endl;
    });


    onTimeUpdated(model->remainingTime());
    onPhaseChanged(model->isResting());
    view->updateStartStopButton(model->isRunning());
}

void TimerController::handleStartStop() {
    if (model->isRunning()) {
        model->stop();
    } else {
        model->start();
    }
}

void TimerController::handleReset() {
    model->reset();
}

void TimerController::handleSkip() {
    model->skip();
}

void TimerController::onTimeUpdated(unsigned seconds) {
    view->updateTimeDisplay(TimerPresenter::formatTime(seconds));

    if (seconds <= 3 && seconds >= 0) {
        player->stop();
        player->setAudioOutput(audioOutput);
        player->setSource(QUrl(!seconds ? "qrc:/beep-09.wav" : "qrc:/beep-07a.wav"));
        // player->setSource(QUrl::fromLocalFile("/home/kali/projects/app/beep-07a.wav"));
        player->play();
    }
}

void TimerController::onPhaseChanged(bool resting) {
    view->updatePhaseDisplay(TimerPresenter::phaseText(resting));
}

void TimerController::onStarted() {
    view->updateStartStopButton(true);
}

void TimerController::onStopped() {
    view->updateStartStopButton(false);
}
