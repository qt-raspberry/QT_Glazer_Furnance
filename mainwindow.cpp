#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGridLayout>
#include <QWidget>
#include "ssgraphs.h"
#include <QResizeEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    newButton(new QPushButton("Button 3"))
{
    ui->setupUi(this);
    //***************** START *************
    // Add Background image from :https://stackoverflow.com/questions/19939938/how-do-i-add-a-background-image-to-the-qmainwindow
//        this->centralWidget()->setStyleSheet(
//             "background-image:url(\":/Pictures/logo3.gif\"); background-position: center;" );
    //end of https://stackoverflow.com/questions/19939938/how-do-i-add-a-background-image-to-the-qmainwindow
     //***************** END *************


    const int rowNumber = 1;
    const int colNumber = 0;
    //newButton->styleSheet() "background-color:green";

   //ui->gridLayout->addWidget(newButton, rowNumber, colNumber);


    auto movie = new QMovie(this);
    movie->setFileName(":/Pictures/70a552e8e955049c8587b2d7606cd6a6.gif");
    //movie->setSpeed(2000);
    connect(movie, &QMovie::frameChanged, [=]{
         ui->pushButton_4->setIcon(movie->currentPixmap());
    });

//    connect(movie, &QMovie::frameChanged, [=]{
//         ui->pushButton_4->setIcon(movie->setSpeed(2000));
//    });
    movie->setSpeed(2000000);
    ui->pushButton_4->setIconSize(QSize(220,220));
    movie->start();

    /*
    QTime time(0, 1, 0);
    time.start();
    //time=time.addSecs(-1);
    ui->label->setText(QTime::currentTime().toString("hh:mm:ss"));

    */
    //From :https://prognotes.net/2017/07/display-time-qt-creator-application/
    timer_1s = new QTimer(this);
    QObject::connect(timer_1s, SIGNAL(timeout()), this, SLOT(UpdateTime()));
    timer_1s->start(1000);
    //ENd of From :https://prognotes.net/2017/07/display-time-qt-creator-application/


    QWidget *datawidget = new QWidget( this );
    //ui->setCentralWidget( datawidget );
    datawidget->setAccessibleName("datawidget");
    datawidget->setStyleSheet(" #datawidget { background-color:#000; } ");


    QObject::connect(ui->chart_button, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
    QObject::connect(ui->start_btn, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));

    //ui->label->setAlignment()
    //Set label font collor
    Label_font();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Label_font(){


    QPalette palette = ui->label->palette();
    palette.setColor(QPalette::WindowText,QColor(255, 255, 255, 127));
    ui->label->setPalette(palette);
    //Or
    //From:https://stackoverflow.com/questions/1464591/how-to-create-a-bold-red-text-label-in-qt
    ui->label->setStyleSheet(" font-size:6pt;  font-weight: bold; color: red");


    ui->label_2->setStyleSheet("#QLabel {\
        position: absolute;\
        top: 200px;\
        left: 200px; z-index: -1;}");




   // ui->label->adjustSize();









}

void MainWindow::resizeEvent(QResizeEvent* event)
{
     //QLabel::resizeEvent(event);

     QFont font = ui->label->font();
     QRect cRect = ui->label->contentsRect();

    if( ui->label->text().isEmpty() )
            return;

     int fontSize = 1;

      while( true )
      {
                  QFont f(font);
                       f.setPixelSize( fontSize );
                  QRect r = QFontMetrics(f).boundingRect( ui->label->text() );
                  if (r.height() <= cRect.height() && r.width() <= cRect.width() )
                        fontSize++;
                  else
                        break;
      }

     font.setPixelSize(fontSize);
     ui->label->setFont(font);
}

void MainWindow::on_pushButton_clicked()
{
    ssGraphs ww;

    ww.show();
}


void MainWindow::UpdateTime()
{
    ui->label->setText(""+QTime::currentTime().toString("hh:mm:ss"));
}



void MainWindow::on_chart_button_clicked()
{
    //ssGraphs ww;

//    ssGraphs ww ;
ww.show();
}

void MainWindow::on_heat_btn_clicked()
{
//   ui->heat_btn->setStyleSheet("background-color: red;");
    //widgets.append(clock);
    //clock.show();
    chart.show();



//heat_btn:pressed {
//    background-color: red;
//}

}

void MainWindow::on_start_btn_clicked()
{
ui->start_btn->setStyleSheet("border-image: url(:/Pictures/Qt menus/btn_on.gif);");
}
