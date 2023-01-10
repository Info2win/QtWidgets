#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    init();
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_buttonBox_accepted()
{
    accept();
}


void Dialog::on_buttonBox_rejected()
{
    reject();
}

void Dialog::add()
{
    QString text = QInputDialog::getText(this,"Add Item","Enter an item to be added");
    if (text.isEmpty()) return;

    // Use the inherited functions of QAbstractModel

    if(model.insertRow(model.rowCount())) // if an empty row inserted to the model
    {
        QModelIndex index = model.index(model.rowCount()-1,0); // get the index of the empty row
        model.setData(index,text);// insert the data to the index
    }
}

void Dialog::remove()
{
    QModelIndex index = ui->listView->currentIndex();
    model.removeRow(index.row());
}

void Dialog::init()
{
    // Set up the data
    list.append("Dog");
    list.append("Cat");
    list.append("Fish");
    list.append("Bird");

    // Set up the model using the data
    model.setStringList(list);

    // Setup the view
    ui->listView->setModel(&model);

    // Build UI

    QPushButton *btnAdd = new QPushButton("Add",this);
    QPushButton *btnRemove = new QPushButton("Remove",this);

    connect(btnAdd,&QPushButton::clicked,this,&Dialog::add);
    connect(btnRemove,&QPushButton::clicked,this,&Dialog::remove);

    ui->buttonBox->addButton(btnAdd,QDialogButtonBox::ActionRole);
    ui->buttonBox->addButton(btnRemove,QDialogButtonBox::ActionRole);

}

