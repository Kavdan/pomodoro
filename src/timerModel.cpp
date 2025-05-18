#include "include/timerModel.h"

TimerModel::TimerModel(unsigned workSeconds, unsigned restSeconds, QObject *parent)
    : QObject(parent),
      running(false),
      resting(false),
      workDuration(workSeconds),
      restDuration(restSeconds),
      remaining(workSeconds) {

    timer.setInterval(INTERVAL_MS);
    connect(&timer, &QTimer::timeout, this, &TimerModel::onTimeout);
}

void TimerModel::start() {
    if (!running) {
        running = true;
        timer.start();
        emit started();
    }
}

void TimerModel::stop() {
    if (running) {
        running = false;
        timer.stop();
        emit stopped();
    }
}

void TimerModel::reset() {
    stop();
    remaining = resting ? restDuration : workDuration;
    emit phaseChanged(resting);
    emit timeUpdated(remaining);
}

void TimerModel::skip() {
    stop();
    resting = !resting;
    remaining = resting ? restDuration : workDuration;
    emit phaseChanged(resting);
    emit timeUpdated(remaining);
}

bool TimerModel::isRunning() const {
    return running;
}

bool TimerModel::isResting() const {
    return resting;
}

unsigned TimerModel::remainingTime() const {
    return remaining;
}

void TimerModel::onTimeout() {
    if (remaining > 0) {
        --remaining;
        emit timeUpdated(remaining);
    } else {
        stop();
        resting = !resting;
        remaining = resting ? restDuration : workDuration;
        emit phaseChanged(resting);
        emit timeUpdated(remaining);
    }
}
