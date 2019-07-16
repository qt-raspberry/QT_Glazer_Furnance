#include "diagram_minut_form.h"
#include "ui_diagram_minut_form.h"

diagram_minut_form::diagram_minut_form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::diagram_minut_form)
{
    ui->setupUi(this);
   Lock_stuation(0);
   Label_pic();
}

diagram_minut_form::~diagram_minut_form()
{
    delete ui;
}
int diagram_minut_form::Lock_stuation(bool lock_sit) {

    ui->horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
    ui->horizontalLayout_2->setSpacing(0.5);
    QLabel s;/*=ui->widget->setStyleSheet("border-image: url(:/Pictures/GSH/photos totally/image40.png);");*/

    //s=ui->widget->setStyleSheet("border-image: url(:/Pictures/GSH/photos totally/image40.png)");
    if (lock_sit==1){
        ui->label_lock_situation->setStyleSheet("image: url(:/Pictures/GSH/photos totally/lock.gif)\
                                                border: 3px solid gray;\
                                                border-top-left-radius: 10px ;\
                                                ");

    }
    else {
         ui->label_lock_situation->setStyleSheet("image: url(:/Pictures/GSH/photos totally/unlock.gif);\
                                                 border: 3px solid gray;\
                                                 border-top-left-radius: 10px;\
                                                 ");
    }

}

void diagram_minut_form::Label_pic(){

//        ui->label_73->setStyleSheet(QString::fromUtf8("position: absolute; top:1px;left:1px;\
//                                    width:10%;\
//                                    border-image:url(:/Pictures/Qt menus/TEMP2.gif);\
//        background-repeat: no-repeat;\
//        border-image-width: 25%;\
//border-radius: 5px;\
//         background-size: 30px 30px;\
//                                    "));


//        QPixmap *tile=new QPixmap(":/Pictures/Qt menus/TEMP2.gif");
//        QPixmap *pixmap=new QPixmap(":/Pictures/Qt menus/TEMP2.gif");
//        pixmap->fill(Qt::transparent);
//        QPainter *painter=new QPainter(pixmap);


//        painter->drawPixmap(0, 0, 29, 49, QPixmap(":/Pictures/Qt menus/TEMP2.gif"));
//        painter->end();

//        ui->label->setPixmap(*pixmap);
//        ui->label->resize(QSize(23,26));

//        QImage yourImage(":/Pictures/Qt menus/TEMP2.gif");
//        QLabel image= new QLabel(centralwidget);
//        ui->label->setGeometry(QRect(20, 10, 371, 311));
//        ui->label->setPixmap(QPixmap(QPixmap::fromImage(yourImage)));


//        QPixmap px(":/Pictures/Qt menus/TEMP2.gif");
//        px = px.scaled( QSize(30,30) );
//        ui->label->setPixmap(px);
////        ui->label->setGeometry(0,0,100,100);
////        ui->label->setSizeIncrement(33,33);
//        if(!px.isNull())
//        {
//        ui->label->setPixmap(px);
//        ui->label->show();
//        }



//        QPixmap px(":/Pictures/Qt menus/TEMP2.gif");
//        ui->label->setPixmap(px);
//        ui->label->setGeometry(10,10,82,82);

}

void diagram_minut_form::Program_number(int Program_number_i,QString program_name) {



    ui->program_name->setText(program_name);
    ui->program_number->setText(QString::number(Program_number_i));



}

void diagram_minut_form::on_label_38_linkHovered(const QString &link)
{
    ui->label_64->setAutoFillBackground(true);
    ui->label_64->setWindowOpacity(0.1);
    ui->label_64->setWindowOpacity(0.35);
    ui->label_64->setAttribute(Qt::WA_TranslucentBackground, false);
    ui->label_64->setStyleSheet("background-color: yellow;");
//    ui->lyaout_3->SetFixedSize;


}
