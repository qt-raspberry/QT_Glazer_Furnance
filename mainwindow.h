#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMovie>
#include <QTimer>
#include <QTime>
#include <QLabel>
#include <QDateEdit>
#include <QtCharts>
#include <QBarSet>
#include <QChartView>
#include "ssgraphs.h"
#include "analogclockwindow.h"
//#include "qt_qthread_qobject_demo-master/widget.h"
#include "diagram_minut_form.h"
#include "sql_program_cl.h"
#include <QColor>
#include <QtDebug>
#include <QDesignerCustomWidgetCollectionInterface>
#include <QDesignerCustomWidgetInterface>


QT_BEGIN_NAMESPACE
class QComboBox;
class QDataWidgetMapper;
class QItemSelectionModel;
class QLabel;
class QLineEdit;
class QPushButton;
class QSqlRelationalTableModel;
class QStandardItemModel;
class QStringListModel;
class QTextEdit;
QT_END_NAMESPACE
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

//#include <QDesignerCustomWidgetInterface>

//class MainWindow : public QObject,public QMainWindow,
//                             public QDesignerCustomWidgetInterface
//{
//    Q_OBJECT
//    Q_INTERFACES(QDesignerCustomWidgetInterface)


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    ssGraphs ww;
    analogclockwindow clock;
    diagram_minut_form chart;
     void resizeEvent(QResizeEvent* event) ;//override;


private slots:
    void on_pushButton_clicked();

    void UpdateTime();

    void on_chart_button_clicked();
    void on_heat_btn_clicked();

    void on_start_btn_clicked();

protected:
    //void resizeEvent(QResizeEvent* event) override;
private:
    Ui::MainWindow *ui;
    QPushButton *newButton;
    QTimer *timer_1s;
    //ssGraphs* newgg;
    void Label_font();



    QLabel *nameLabel;
    QLabel *addressLabel;
    QLabel *typeLabel;
    QLineEdit *nameEdit;
    QTextEdit *addressEdit;
    QComboBox *typeComboBox;

    QPushButton *previousButton;

    QSqlRelationalTableModel *model;
    QItemSelectionModel *selectionModel;
    QDataWidgetMapper *mapper;
    int typeIndex;


    QList<QDesignerCustomWidgetInterface*> widgets;

};

#endif // MAINWINDOW_H
