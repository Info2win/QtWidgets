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


void Dialog::on_buttonBox_accepted()
{
    QMessageBox::information(this,"Selected","You have selected: \r\n" + ui->lineEdit->text());
    accept();
}


void Dialog::on_buttonBox_rejected()
{
    reject();
}


void Dialog::on_btnSelect_clicked()
{
    Dialog2 *selections = new Dialog2();
    selections->setSelected(ui->lineEdit->text());
    selections->exec();
    ui->lineEdit->setText(selections->selected());
}

