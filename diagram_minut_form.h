#ifndef DIAGRAM_MINUT_FORM_H
#define DIAGRAM_MINUT_FORM_H

#include <QWidget>

namespace Ui {
class diagram_minut_form;
}

class diagram_minut_form : public QWidget
{
    Q_OBJECT

public:
    explicit diagram_minut_form(QWidget *parent = nullptr);
    ~diagram_minut_form();
     int Lock_stuation(bool lock_sit) ;
     void Program_number(int Program_number_i,QString program_name);

private slots:
     void on_label_38_linkHovered(const QString &link);

private:
    Ui::diagram_minut_form *ui;
};

#endif // DIAGRAM_MINUT_FORM_H
