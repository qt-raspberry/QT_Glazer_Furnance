#ifndef SQL_PROGRAM_CL_H
#define SQL_PROGRAM_CL_H

#include <QWidget>
//#include <QVBoxLayout>
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

class sql_program_cl : public QWidget
        {
    Q_OBJECT
public:
     sql_program_cl(QWidget *parent = 0);
//    sql_program_cl();
    void updateButtons(int row);

private:
    void setupModel();

    QLabel *nameLabel;
    QLabel *addressLabel;
    QLabel *typeLabel;
    QLineEdit *nameEdit;
    QTextEdit *addressEdit;
    QComboBox *typeComboBox;
    QPushButton *nextButton;
    QPushButton *previousButton;

    QSqlRelationalTableModel *model;
    QItemSelectionModel *selectionModel;
    QDataWidgetMapper *mapper;
    int typeIndex;

};

#endif // SQL_PROGRAM_CL_H
