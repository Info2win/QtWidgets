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

void Dialog::init()
{
   /* QStringList headers;
    headers << "My Item Label";
    model.setHorizontalHeaderLabels(headers); */

    QStandardItem *root = model.invisibleRootItem();

    for(int p=0; p<50; p++)
    {
        QStandardItem* standardParentItem = new QStandardItem (QString("Parent %0").arg(p));
        root->appendRow(standardParentItem);

        for(int c=0; c<10; c++)
        {
            QStandardItem* standardChildItem = new QStandardItem (QString("Child %0").arg(c));
            standardParentItem->appendRow(standardChildItem);

            for(int s=0; s<5; s++)
            {
                QStandardItem* standardSubItem = new QStandardItem (QString("Child %0").arg(s));
                standardChildItem->appendRow(standardSubItem);
            }
        }
    }
    ui->treeView->setModel(&model);
}

