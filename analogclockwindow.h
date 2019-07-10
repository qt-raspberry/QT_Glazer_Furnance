#ifndef ANALOGCLOCK_H
#define ANALOGCLOCK_H

#include <QWidget>

//class analogclockwindow : public QWidget

#include <QtDesigner/QDesignerExportWidget>

class QDESIGNER_WIDGET_EXPORT analogclockwindow : public QWidget
{
    Q_OBJECT

public:
    analogclockwindow(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);
};

#endif
