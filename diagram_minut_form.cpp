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


    QLabel s;/*=ui->widget->setStyleSheet("border-image: url(:/Pictures/GSH/photos totally/image40.png);");*/

    //s=ui->widget->setStyleSheet("border-image: url(:/Pictures/GSH/photos totally/image40.png)");
    if (lock_sit==1){
        ui->label_lock_situation->setStyleSheet("border-image: url(:/Pictures/GSH/photos totally/lock.gif)");

    }
    else {
         ui->label_lock_situation->setStyleSheet("border-image: url(:/Pictures/GSH/photos totally/unlock.gif)");
    }

}


void diagram_minut_form::Program_number(int Program_number_i,QString program_name) {



    ui->program_name->setText(program_name);
    ui->program_number->setText(QString::number(Program_number_i));



}
