#include "include/timerView.h"

TimerView::TimerView(QWidget *parent) : QWidget(parent) {
  timeLabel = new QLabel("00:00", this);
  timeLabel->setAlignment(Qt::AlignCenter);
  QFont font = timeLabel->font();
  font.setPointSize(24);
  timeLabel->setFont(font);

  phaseLabel = new QLabel("Работа", this);
  phaseLabel->setAlignment(Qt::AlignCenter);

  startStopButton = new QPushButton("Start", this);
  resetButton = new QPushButton("Reset", this);
  skipButton = new QPushButton("Skip", this);

  startStopButton->setCursor(Qt::PointingHandCursor);
  resetButton->setCursor(Qt::PointingHandCursor);
  skipButton->setCursor(Qt::PointingHandCursor);

  QVBoxLayout *mainLayout = new QVBoxLayout(this);
  QHBoxLayout *buttonLayout = new QHBoxLayout();

  buttonLayout->addWidget(skipButton);
  buttonLayout->addWidget(resetButton);

  mainLayout->addWidget(timeLabel);
  mainLayout->addWidget(phaseLabel);
  mainLayout->addSpacing(50);
  mainLayout->addLayout(buttonLayout);
  mainLayout->addWidget(startStopButton);

  setLayout(mainLayout);

  connect(startStopButton, &QPushButton::clicked, this,
          &TimerView::startStopClicked);
  connect(resetButton, &QPushButton::clicked, this, &TimerView::resetClicked);
  connect(skipButton, &QPushButton::clicked, this, &TimerView::skipClicked);
}

void TimerView::updateTimeDisplay(const QString &text) {
  timeLabel->setText(text);
}

void TimerView::updatePhaseDisplay(const QString &text) {
  phaseLabel->setText(text);
}

void TimerView::updateStartStopButton(bool running) {
  if (running) {
    startStopButton->setText("Stop");
    startStopButton->setStyleSheet(
        "background-color: red; color: white; border: none; padding: 10px; "
        "border-radius: 5px;");
  } else {
    startStopButton->setText("Start");
    startStopButton->setStyleSheet(
        "background-color: #009ac9; color: white; border: none; padding: 10px; "
        "border-radius: 5px;");
  }
}
