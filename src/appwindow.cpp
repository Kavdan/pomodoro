#include "include/appwindow.h"
#include "ui_appwindow.h"

#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

AppWindow::AppWindow(QWidget *parent)
    : QMainWindow(parent),
      timerLabel(new QLabel(this)),
      controlButton(new QPushButton(this)),
      resetButton(new QPushButton(this)),
      skipButton(new QPushButton(this)),
      phase(new QLabel(this)),
      timer(nullptr),
      timerPresenter(nullptr),
     ui(new Ui::AppWindow)
{
    ui->setupUi(this);
    setupUI();
}

AppWindow::~AppWindow()
{
    delete ui;
}

void AppWindow::setupUI(){
      QWidget *central = new QWidget(this);
      QVBoxLayout *layout = new QVBoxLayout(central);

      timerLabel->setAlignment(Qt::AlignCenter);
      QFont font = timerLabel->font();
      font.setPointSize(24);
      timerLabel->setFont(font);
      timerLabel->setText("00:00");
      timerLabel->setMinimumHeight(50);

      phase->setAlignment(Qt::AlignCenter);

      controlButton->setText("Start");
      controlButton->setStyleSheet("background-color:#009ac9;"
                                   "color:white;"
                                   "border: none;"
                                   "padding: 10px;"
                                   "border-radius: 5px;");
      controlButton->setCursor(Qt::PointingHandCursor);

      QHBoxLayout *qhbox = new QHBoxLayout();

      skipButton->setText("skip");
      skipButton->setMinimumWidth(controlButton->width()/2);

      resetButton->setText("reset");
      resetButton->setMinimumWidth(skipButton->width());

      skipButton->setCursor(Qt::PointingHandCursor);
      resetButton->setCursor(Qt::PointingHandCursor);

      qhbox->addWidget(skipButton);
      qhbox->addWidget(resetButton);

      layout->addWidget(timerLabel);
      layout->addWidget(phase);
      layout->addSpacing(200);
      layout->addLayout(qhbox);
      layout->addWidget(controlButton);

      central->setLayout(layout);
      this->setCentralWidget(central);
}

void AppWindow::run(unsigned workSeconds, unsigned restSeconds){
    timer = new Timer(workSeconds, restSeconds);
    timerPresenter = new TimerPresenter(timer,
                                        timerLabel,
                                        controlButton,
                                        resetButton,
                                        skipButton,
                                        phase);
}
