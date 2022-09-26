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


void Dialog::on_btnOK_clicked()
{
 QString icecream = getOption(ui->grpIcecream);
 QString syrup = getOption(ui->grpSyrup);
 QString topping = getOption(ui->grpToppings);
 QString size = getOption(ui->grpSize);

 QString order =
   "Order:\nFlavor: " + icecream + "\n"
         + "Syrup: "+ syrup + "\n"
         + "Topping: " + topping + "\n"
         + "Size: " + size;
 QMessageBox::information(this,"Order",order);
 accept();
}


void Dialog::on_btnCancel_clicked()
{
    QMessageBox::critical(this,"What!!!","You did not want icecream!");
}

QString Dialog::getOption(QObject *obj)
{
    QString value = "None";
    QList<QRadioButton*> lst = obj->findChildren<QRadioButton*>(QString(),Qt::FindDirectChildrenOnly);

    foreach(QRadioButton* radiobtn, lst)
    {
        if(radiobtn->isChecked())
        {
            value = radiobtn->text();
            break;
        }
    }

    return value;
}

