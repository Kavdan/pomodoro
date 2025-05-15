#include "include/timer.h"
#include <iomanip>
#include <sstream>

Timer::Timer(unsigned workSeconds,
             unsigned restSeconds,
             QObject *parent)
             : workSeconds(workSeconds),
             restSeconds(restSeconds),
             running(false),
             resting(false),
             remainingSeconds(workSeconds)
             {
    connect(&timer, &QTimer::timeout, this, &Timer::onTimeout);
    timer.setInterval(INTERVAL_MS);
}

void Timer::start(){
    if(running) return;
    if(remainingSeconds <= 0)
        remainingSeconds = running ? workSeconds : restSeconds;
    running = true;
    timer.start();
    emit timerStarted();
    emit timeUpdated(formatTime(remainingSeconds));
}

void Timer::stop(){
    if(!running) return;
    running = false;
    timer.stop();
    emit timerStopped();
}

void Timer::reset(){
    if(running || resting){
        timer.stop();
        remainingSeconds = running ? workSeconds : restSeconds;
        emit timeUpdated(formatTime(remainingSeconds));
        emit timerStopped();
     }
}

void Timer::skipPhase(){
    resting = !resting;

    stop();
    remainingSeconds = resting ? restSeconds : workSeconds;
    emit phaseChanged(resting);
    emit timeUpdated(formatTime(remainingSeconds));
}

void Timer::onTimeout(){
    if(--remainingSeconds > 0){
    } else {
        stop();
        resting = !resting;
        remainingSeconds = resting ? restSeconds : workSeconds;
        emit phaseChanged(resting);
    }
    emit timeUpdated(formatTime(remainingSeconds));
}

QString Timer::formatTime(unsigned totalSeconds) {
    int minutes = totalSeconds / 60;
    int seconds = totalSeconds % 60;
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << minutes << ":"
        << std::setw(2) << std::setfill('0') << seconds;
    return QString::fromStdString(oss.str());
}

bool Timer::isResting() {
    return resting;
}

bool Timer::isRunning() {
    return running;
}

QString Timer::getWorkSeconds(){
    return formatTime(workSeconds);
}
