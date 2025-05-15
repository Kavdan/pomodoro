#include "include/timerPresenter.h"
#include "include/timer.h"

TimerPresenter::TimerPresenter(Timer *timer,
                               QLabel *label,
                               QPushButton *controllButton,
                               QPushButton *resetButton,
                               QPushButton *skipButton,
                               QLabel *phase,
                               QObject *parent)
    : timer(timer),
      label(label),
      controllButton(controllButton),
      resetButton(resetButton),
      skipButton(skipButton),
      phase(phase){
    connect(controllButton, &QPushButton::clicked, this, &TimerPresenter::onButtonClicked);
    connect(resetButton, &QPushButton::clicked, this, &TimerPresenter::onResetClicked);
    connect(skipButton, &QPushButton::clicked, this, &TimerPresenter::onSkipClicked);

    connect(timer, &Timer::timerStarted, this, &TimerPresenter::onStarted);
    connect(timer, &Timer::timerStopped, this, &TimerPresenter::onStopped);
    connect(timer, &Timer::timeUpdated, this, &TimerPresenter::updateTime);
    connect(timer, &Timer::phaseChanged, this, &TimerPresenter::updatePhase);

    label->setText(timer->getWorkSeconds());
    controllButton->setText(START_BUTTON_TXT);
    phase->setText(PHASE_WORKING_TXT);
}

void TimerPresenter::onButtonClicked() {
    if(timer->isRunning())
        timer->stop();
    else
        timer->start();
}

void TimerPresenter::onResetClicked(){
    timer->reset();
}

void TimerPresenter::onSkipClicked() {
    timer->skipPhase();
}

void TimerPresenter::onStarted() {
    controllButton->setText(STOP_BUTTON_TXT);
    controllButton->setStyleSheet("background-color:red;"
                                   "color:white;"
                                   "border: none;"
                                   "padding: 10px;"
                                   "border-radius: 5px;");

}

void TimerPresenter::onStopped() {
    controllButton->setText(START_BUTTON_TXT);
    controllButton->setStyleSheet("background-color:#009ac9;"
                                   "color:white;"
                                   "border: none;"
                                   "padding: 10px;"
                                   "border-radius: 5px;");
}

void TimerPresenter::updateTime(const QString &time){
    label->setText(time);
}

void TimerPresenter::updatePhase(bool resting){
    if(resting)
        phase->setText(PHASE_RESTING_TXT);
    else
        phase->setText(PHASE_WORKING_TXT);
}
