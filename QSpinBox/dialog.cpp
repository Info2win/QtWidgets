#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    load();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::load()
{
    QFile file("data.ilker");
    if(!file.exists()) return;
    if(!file.open(QIODevice::ReadOnly))
    {
       QMessageBox::critical(this,"Error","Could not load the file");
       return;
    }
    QDataStream stream(&file);
    QString name;
    int age;
    double Qty;
    stream >> name;
    stream >> age;
    stream >> Qty;

    file.close();

    ui->lineEdit->setText(name);
    ui->spinBox->setValue(age);
    ui->doubleSpinBox->setValue(Qty);
}

void Dialog::save()
{
    QFile file("data.ilker");
    if(!file.open(QIODevice::WriteOnly))
    {
       QMessageBox::critical(this,"Error","Could not save the file");
       return;
    }
    QDataStream stream(&file);
    stream << ui->lineEdit->text();
    stream << ui->spinBox->value();
    stream << ui->doubleSpinBox->value();

    file.close();
    QMessageBox::information(this,"Saved","Saved this file");
}


void Dialog::on_buttonBox_accepted()
{
    save();
    accept();
}


void Dialog::on_buttonBox_rejected()
{
    reject();
}

