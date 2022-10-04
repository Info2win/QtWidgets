#include "dialog2.h"
#include "ui_dialog2.h"

Dialog2::Dialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog2)
{
    ui->setupUi(this);
    init();
}

Dialog2::~Dialog2()
{
    delete ui;
}

QString Dialog2::selected()
{
    return selectedIcon;
}

void Dialog2::setSelected(QString selected)
{
    selectedIcon = "";

    for(int i=0; i< ui->listWidget->count();i++)
    {
        QListWidgetItem *item = ui->listWidget->item(i);

        if(item->text() == selected)
        {
            item->setSelected(true);
            selectedIcon = selected;
            return;
        }
    }
}

void Dialog2::on_buttonBox_accepted()
{
    if(ui->listWidget->currentItem())
    {
        selectedIcon = ui->listWidget->currentItem()->text();
    }
    accept();
}


void Dialog2::on_buttonBox_rejected()
{
    reject();
}

void Dialog2::init()
{
    QDir root = QDir(":/files/images");

    foreach(QFileInfo file,root.entryInfoList())
    {
        QListWidgetItem *item = new QListWidgetItem();
        item->setText(file.absoluteFilePath());
        item->setIcon(QIcon(file.absoluteFilePath()));
        ui->listWidget->addItem(item);
    }
}

