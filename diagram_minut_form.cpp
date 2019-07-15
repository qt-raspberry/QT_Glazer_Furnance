#include "diagram_minut_form.h"
#include "ui_diagram_minut_form.h"

diagram_minut_form::diagram_minut_form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::diagram_minut_form)
{
    ui->setupUi(this);
   Lock_stuation(0);
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
    ui->lyaout_3->SetFixedSize;
//    ui->lyaout_3.set


}
