#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include <QIcon>
#include <QWidget>
#include "ssgraphs.h"
#include "switch.h"


int main0(int argc, char *argv[]) {
    QApplication application(argc, argv);
    QWidget container;
    QVBoxLayout mainLayout;
    container.setLayout(&mainLayout);

    Switch* switch1 = new Switch("SWITCH");
    mainLayout.addWidget(switch1);
    Switch* switch2 = new Switch("SWITCH");
    mainLayout.addWidget(switch2);
    switch2->setDisabled(true);
    Switch* switch3 = new Switch("SWITCH");
    mainLayout.addWidget(switch3);
    switch3->setLayoutDirection(Qt::RightToLeft);
    Switch* switch4 = new Switch("SWITCH");
    mainLayout.addWidget(switch4);
    switch4->setLayoutDirection(Qt::RightToLeft);
    switch4->setChecked(true);
    switch4->setDisabled(true);

    QButtonGroup bg;
    Switch* item1 = new Switch("ITEM1");
    Switch* item2 = new Switch("ITEM2");
    bg.addButton(item1);
    bg.addButton(item2);
    mainLayout.addWidget(item1);
    mainLayout.addWidget(item2);
    mainLayout.setMargin(100);

    container.show();
    return application.exec();
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QPushButton button;

    QVBoxLayout mainLayout;
        w.setLayout(&mainLayout);

        Switch* switch1 = new Switch("SWITCH");
        mainLayout.addWidget(switch1);
        Switch* switch2 = new Switch("SWITCH");
        mainLayout.addWidget(switch2);
        switch2->setDisabled(true);
        Switch* switch3 = new Switch("SWITCH");
        mainLayout.addWidget(switch3);
        switch3->setLayoutDirection(Qt::RightToLeft);
        Switch* switch4 = new Switch("SWITCH");
        mainLayout.addWidget(switch4);
        switch4->setLayoutDirection(Qt::RightToLeft);
        switch4->setChecked(true);
        switch4->setDisabled(true);

        QButtonGroup bg;
        Switch* item1 = new Switch("ITEM1");
        Switch* item2 = new Switch("ITEM2");
        bg.addButton(item1);
        bg.addButton(item2);
        mainLayout.addWidget(item1);
        mainLayout.addWidget(item2);
        mainLayout.setMargin(100);

    // MainWindow:
    button.setText("  سلام دوستان عزیز این زیباتر است  ");
    button.setToolTip("A tooltip");
    QFont font("B Yekan");
    button.setFont(font);
    button.iconSize();
    button.windowIcon();
    QIcon icon("/home/so/Pictures/ss.png");
    button.setIcon(icon);
    //button.pressed("{background-color: rgb(200, 200, 200); }");

    //button.show();
    w.show();
   //w->clock->show();






    return a.exec();
}
