#include "mymesg.h"
#include "ui_mymesg.h"

Mymesg::Mymesg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Mymesg)
{
    ui->setupUi(this);
	setWindowFlags(windowFlags()&~Qt::WindowMinMaxButtonsHint | Qt::WindowMinimizeButtonHint);
	setFixedSize(350,100);
    count = 0;
    ui->bar_MyDIsplay->setRange(0,100);
    ui->lab_MyDisplay->setText(QString("The device is being configured, please wait.."));
    mytimer = new QTimer(this);
    connect(mytimer,SIGNAL(timeout()),this,SLOT(timeoutfunc()));//注意第一个为timer
    mytimer->start(300);
}

Mymesg::~Mymesg()
{
    delete mytimer;
    delete ui;
}

void Mymesg::timeoutfunc()
{
    count++;
    ui->bar_MyDIsplay->setValue(count);
    if(100 == count){
        mytimer->stop();
        count = 0;
    }
}
