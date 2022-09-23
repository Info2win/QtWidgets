#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_btnCheckable_clicked()
{
    qDebug() << "Checked: " << ui->btnCheckable->isChecked();
}


void Dialog::on_btnAutoRepeat_clicked()
{
    qInfo() << "Clicked";
}


void Dialog::on_pushButton_5_clicked()
{
    qInfo() << "Default button clicked";
}


void Dialog::on_btnIsChecked_clicked()
{
    QString message;
    if(ui->btnCheckable->isChecked())
        message = "Yes it is cheched";
    else message = "No it is not cheched";

    QMessageBox::information(this,"Checked",message);
}


void Dialog::on_btnToggleAutoRepeat_clicked()
{
    bool value = !ui->btnAutoRepeat->autoRepeat();
    ui->btnAutoRepeat->setAutoRepeat(value);
    qDebug() << "Repeat: " << ui->btnAutoRepeat->autoRepeat();
}


void Dialog::on_btnToggleDefault_clicked()
{
    bool value = !ui->pushButton_5->isDefault();
    ui->pushButton_5->setDefault(value);
    qDebug() << "Default : " << ui->pushButton_5->isDefault();
}


void Dialog::on_pushButton_7_clicked()
{
    accept();
}

