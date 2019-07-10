#include "ssgraphs.h"
#include "ui_ssgraphs.h"
//namespace  ui{
//class Ui;
//}

ssGraphs::ssGraphs(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ssGraphs)
{


//    ui= ssGraphs(this) ;


    ui->setupUi(this);
    ////////PIE CHART///////////////////////////////////////////////////////////////////////

        QPieSeries *series = new QPieSeries();
        series->append("Jane", 10);
        series->append("Joe", 20);
        series->append("Andy", 30);
        series->append("Barbara", 40);
        series->append("Jason", 50);

        QPieSlice *slice = series->slices().at(1);
        slice->setExploded();
        slice->setLabelVisible();
        slice->setPen(QPen(Qt::darkGreen, 2));
        slice->setBrush(Qt::green);

        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Students Performance");

        QChartView *chartView = new QChartView(chart);
//    chartView->setParent(&w);
    chartView->setParent(ui->verticalFrame);
}

ssGraphs::~ssGraphs()
{
    delete ui;
}
