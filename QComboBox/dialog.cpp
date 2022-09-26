#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    on_init();
    load();
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_clicked()
{
    QSettings settings("MySoft","QComboBoxApp");
    settings.setValue("settings",ui->comboBox->currentIndex());
    QMessageBox::information(this,"Saved","Selection saved, please close and re-run the application.");
}


void Dialog::on_comboBox_currentIndexChanged(int index)
{
    ui->lblSelected->setText(QString::number(index)+ "= " + ui->comboBox->currentText());
}

void Dialog::on_init()
{
    ui->comboBox->clear();

    for(int i=0; i<10; i++)
        ui->comboBox->addItem("Item number: "+ QString::number(i));
}

void Dialog::load()
{
    QSettings settings("MySoft","QComboBoxApp");
    QVariant value = settings.value("settings",0);

    bool ok;
    int index = value.toInt(&ok);
    if(!ok)
    {
        QMessageBox::critical(this,"Loading Error","Error accured while trying to load selection!");
        return;
    }

    if(index < ui->comboBox->count())
    {
        qInfo() << ui->comboBox->currentIndex();
        ui->comboBox->setCurrentIndex(index);
    }
    else
    {
        ui->comboBox->setCurrentIndex(0);
    }
}

