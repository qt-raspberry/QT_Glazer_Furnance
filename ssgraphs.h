#ifndef SSGRAPHS_H
#define SSGRAPHS_H

#include <QWidget>

#include <QtCharts>
#include <QChartView>

#include <QBarSet>
#include <QBarSeries>

#include <QPieSeries>
#include <QPieSlice>
namespace Ui {
class ssGraphs;
}

class ssGraphs : public QWidget
{
    Q_OBJECT

public:
    explicit ssGraphs(QWidget *parent = nullptr);
    ~ssGraphs();



private:
    Ui::ssGraphs *ui;
};

#endif // SSGRAPHS_H
