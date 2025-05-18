#include "include/appwindow.h"
#include "include/timerModel.h"
#include "include/timerView.h"
#include "include/timerController.h"

#include "ui_appwindow.h"

#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

AppWindow::AppWindow(QWidget *parent)
    : QMainWindow(parent),
     ui(new Ui::AppWindow)
{
    ui->setupUi(this);
}

AppWindow::~AppWindow()
{
    delete model;
    delete view;
    delete controller;
    delete ui;
}

void AppWindow::setupUI(){

}

void AppWindow::run(unsigned workSeconds, unsigned restSeconds){
    model = new TimerModel(workSeconds, restSeconds, this);
    view = new TimerView(this);
    controller = new TimerController(model, view, this);

    setCentralWidget(view);
}
