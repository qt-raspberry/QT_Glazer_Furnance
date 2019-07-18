#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

private:
    Ui::Widget *ui;
    QThread *thread;

    void setupConnections();                // Sets up all connection between the components; handles the creation and loading of worker, thread and timer

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void receiveThreadStatus(QString msg);  // Retrieves some message from the worker (currently: "Idle"|"Working") that is displayed in the label
    void setThreadState();                  // Toggle idleness of Worker; idelness is automatically turned off whenever work amount is changed or work is finished
    void setWorkAmount(int workAmount);     // Set new work amount via the spinbox
    void setWorkSpeed(int workSpeed);       // Set how fast a single work chunk is processed via the slider
    void receiveFinished();                 // Handle sendFinished() signal from worker when work is finished or work amount is changed
    void receiveProgress(int workDone, int workSpeed);     // Receive current work done by worker plus speed of processing a single chunk per step and display in progressbar

signals:
    void toggleThread();                    // Change worker's idleness
    void sendWorkAmount(int workAmount);    // Change work amount of worker
    void sendWorkSpeed(int workSpeed);      // Change work speed of worker
};

#endif // WIDGET_H
