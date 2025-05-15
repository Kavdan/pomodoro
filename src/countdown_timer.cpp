#include <countdown_timer.h>

QString CountdownTimer::secondsToTimeString(int totalSeconds) {
    int minutes = totalSeconds / 60;
    int seconds = totalSeconds % 60;

    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << minutes
        << ":"
        << std::setw(2) << std::setfill('0') << seconds;

   return QString::fromStdString(oss.str());
}

CountdownTimer::CountdownTimer(int startSeconds,
                               int restSeconds,
                               QLabel *label,
                               QPushButton *button,
                               QObject* parent)
        : QObject(parent),
          label(label),
          button(button),
          remainingSeconds(startSeconds),
          startSeconds(startSeconds),
          restSeconds(restSeconds),
          isRunning(false),
          isResting(false){
        connect(&timer, &QTimer::timeout, this, &CountdownTimer::updateCountdown);
        label->setText(this->secondsToTimeString(startSeconds));
        button->setText("Start");
        timer.setInterval(1000);
    }

CountdownTimer::~CountdownTimer(){
    delete button;
    delete label;
}

void CountdownTimer::updateCountdown() {
        if (remainingSeconds > 0) {
            remainingSeconds--;
            label->setText(this->secondsToTimeString(remainingSeconds));
        } else {
            timer.stop();
            isRunning = false;
            isResting = !isResting;
            label->setText(
                isResting ?
                this->secondsToTimeString(restSeconds) :
                this->secondsToTimeString(startSeconds));
            button->setText("Start");
        }
}

void CountdownTimer::startTimer() {
    if(!isRunning){
        if(!remainingSeconds)
            remainingSeconds = isResting ? restSeconds : startSeconds;
        isRunning = true;
        button->setText("Stop");
        timer.start();
    }
}

void CountdownTimer::stopTimer() {
    if(isRunning){
        isRunning = false;
        button->setText("Start");
        timer.stop();
    }
}

