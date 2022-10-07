#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_accepted()
{
    selected = ui->comboBox->currentText() + " ";
    accept();
}


void Dialog::on_buttonBox_rejected()
{
    reject();
}

const QString &Dialog::getSelected() const
{
    return selected;
}

void Dialog::setList(QStringList list)
{
    ui->comboBox->addItems(list);
}

