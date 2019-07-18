#include "widget.h"
#include "worker.h"
#include "ui_widget.h"
#include <QTimer>
#include <QRect>
#include <QApplication>
#include <iostream>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // Further customization of the UI
    ui->labelWorkerStatus->setAlignment(Qt::AlignCenter);

    ui->gridLayout->setSizeConstraint(QLayout::SetFixedSize);

    //ui->vsliderWorkSpeed->setStyleSheet("QSlider::groove:horizontal {border: 1px solid #999999; height: 18px; border-radius: 9px; } QSlider::handle:horizontal { width: 18px; background-image: url(:/slider-knob.png) } QSlider::add-page:qlineargradient { background: lightgrey; border-top-right-radius: 9px; border-bottom-right-radius: 9px; border-top-left-radius: 0px; border-bottom-left-radius: 0px; } QSlider::sub-page:qlineargradient { background: blue; border-top-right-radius: 0px; border-bottom-right-radius: 0px; border-top-left-radius: 9px; border-bottom-left-radius: 9px;}");
    // FIXME For some reasone stylesheets no longer work?!
    ui->progressBarWork->setStyleSheet("QprogressBarWork:horizontal {border: 1px solid gray; border-radius: 10px; background: white; padding: 1px;} QprogressBarWork::chunk:horizontal {background: qlineargradient(x1: 0, y1: 0.5, x2: 1, y2: 0.5, stop: 0 green, stop: 1 lightgreen); border-radius: 10px;}");
    ui->progressBarWork->setAlignment(Qt::AlignCenter);
    ui->progressBarWork->setMaximum(ui->spinBoxWorkAmount->value());

    ui->sliderWorkSpeed->setValue((int)(ui->sliderWorkSpeed->maximum()/2.));

    setupConnections();

    ui->progressBarWork->setFormat("0 out of " + QString::number(ui->progressBarWork->maximum()) + " | [time per chunk : " + QString::number(ui->sliderWorkSpeed->value() * 10) + "ms]");
}

Widget::~Widget()
{
    // Quit thread
    thread->quit();
    // Wait for it to be closed properly
    while(!thread->isFinished());
    // Delete thread and UI
    delete thread;
    delete ui;
}

void Widget::setupConnections()
{
    // Slots and signals
    // Connect buttons to slots
    connect(ui->buttonToggleWorker, SIGNAL(clicked()), this, SLOT(setThreadState()));
    connect(ui->spinBoxWorkAmount, SIGNAL(valueChanged(int)), this, SLOT(setWorkAmount(int)));
    connect(ui->sliderWorkSpeed, SIGNAL(valueChanged(int)), this, SLOT(setWorkSpeed(int)));

    // Create thread, worker and timer
    thread = new QThread();
    // Important that both the worker and timer are NOT members of this widget class otherwise thread affinity will not change at all!
    Worker *worker = new Worker();
    QTimer *timer = new QTimer();
    timer->setInterval(0);  // Timer's inteveral set to 0 means that timer will trigger an event as soon as there are no other events to be processed

    // Connect worker to widget and vice verser (buttons, progressBarWork)
    // Connect timer to worker
    connect(worker, SIGNAL(sendThreadStatus(QString)), this, SLOT(receiveThreadStatus(QString)));
    connect(worker, SIGNAL(sendFinished()), this, SLOT(receiveFinished()));
    connect(worker, SIGNAL(sendProgress(int, int)), this, SLOT(receiveProgress(int, int)));

    connect(this, SIGNAL(sendWorkAmount(int)), worker, SLOT(receiveWorkAmount(int)));
    connect(this, SIGNAL(sendWorkSpeed(int)), worker, SLOT(receiveWorkSpeed(int)));
    connect(this, SIGNAL(toggleThread()), worker, SLOT(toggle()));

    connect(timer, SIGNAL(timeout()), worker, SLOT(doWork()));
    connect(thread, SIGNAL(started()), timer, SLOT(start()));

    // Mark timer and worker for deletion ones the thread is stopped
    connect(thread, SIGNAL(finished()), worker, SLOT(deleteLater()));
    connect(thread, SIGNAL(finished()), timer, SLOT(deleteLater()));
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    

    // Start timer and move to thread
    timer->moveToThread(thread);

    // Move worker to thread
    worker->moveToThread(thread);

    // Send initial work amount and speed to worker
    emit sendWorkAmount(ui->spinBoxWorkAmount->value());
    emit sendWorkSpeed(ui->sliderWorkSpeed->value() * 10);

    // Start main event loop of thread
    thread->start();
}

void Widget::receiveThreadStatus(QString msg)
{
    ui->labelWorkerStatus->setText(msg);
}

void Widget::receiveProgress(int workDone, int workSpeed)
{
    ui->progressBarWork->setValue(workDone);
    ui->progressBarWork->setFormat(QString::number(workDone) + " out of " + QString::number(ui->progressBarWork->maximum()) + " | [time per chunk : " + QString::number(workSpeed) + "ms]");
}

void Widget::setThreadState()
{
    if(!ui->buttonToggleWorker->text().compare("Halt"))
        ui->buttonToggleWorker->setText("Start");

    else
    {
        ui->buttonToggleWorker->setText("Halt");
    }

    emit toggleThread();
}


// FIXME Whenever progress is shown and spinbox triggers change in work amount the current progress is not recent to 0 (so we get something like 25 out of 5 with 25 being the previous workDone and 5 being the new workAmount)
void Widget::setWorkAmount(int workAmount)
{
    ui->progressBarWork->setMaximum(workAmount);
    ui->progressBarWork->setValue(0);
    ui->progressBarWork->setFormat("0 out of " + QString::number(workAmount) + " | [time per chunk : " + QString::number(ui->sliderWorkSpeed->value() * 10) + "ms]");
    emit sendWorkAmount(workAmount);
}

// FIXME Changing speed right after BUG above appears displays work done that should be 0 in this case
void Widget::setWorkSpeed(int workSpeed)
{
    int _workSpeed = workSpeed * 10;
    ui->progressBarWork->setFormat(QString::number(ui->progressBarWork->value()) + " out of " + QString::number(ui->progressBarWork->maximum()) + " | [time per chunk : " + QString::number(_workSpeed) + "ms]");
    emit sendWorkSpeed(_workSpeed);
}

void Widget::receiveFinished()
{
    //setThreadState();
    ui->buttonToggleWorker->setText("Start");
    ui->progressBarWork->setFormat("0 out of " + QString::number(ui->spinBoxWorkAmount->value()) + " | [time per chunk : " + QString::number(ui->sliderWorkSpeed->value() * 10) + "ms]");
}
