#include "worker.h"
#include <iostream>

#include <QMutexLocker>

Worker::Worker(QObject *parent) :
    QObject(parent),
    active(false),
    progressToggleTerminal(false),
    workAmount(0),
    workDone(0),
    workSpeed(10)
{
}

void Worker::setThreadStatus(QString status)
{
    emit sendThreadStatus(status);
}

void Worker::doWork()
{
    // Do not put an infinite loop here! Otherwise the thread the object is running on will be 100% occupied with the loop and no signals will be processed!!!
    if(active)
    {
        setThreadStatus("Working");
        // Do work
        workChunk();
    }
    else setThreadStatus("    Idle    ");
}

void Worker::workChunk()
{
    QThread::msleep(workSpeed);
    if(workDone < workAmount)
    {
        workDone++;
        emit sendProgress(workDone, workSpeed);
    }
    else
    {
        emit sendFinished();
        active = false;
    }
}

void Worker::toggle()
{
    QMutexLocker locker(&lock);
    active = !active;

    if(workDone == workAmount)
    {
        workDone = 0;
        emit sendProgress(workDone, workSpeed);
    }
}

void Worker::receiveWorkAmount(int _workAmount)
{
    // Load new work amount
    workAmount = _workAmount;
    // Reset progress
    workDone = 0;
    // Automatically stop thread so that the user can choose when to start the processing of the assigned work
    active = false;
    // Emit finished (even though this might not be the case) since we are throwing away the previous work
    emit sendFinished();
}

void Worker::receiveWorkSpeed(int _workSpeed)
{
    QMutexLocker locker(&lock);
    workSpeed = _workSpeed;
}
