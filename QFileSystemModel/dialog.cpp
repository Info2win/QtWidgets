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


void Dialog::on_treeView_activated(const QModelIndex &index)
{
    QString path = dirModel.filePath(index);
    ui->listView->setRootIndex(fileModel.setRootPath(path));
}

void Dialog::init()
{
    dirModel.setRootPath(QDir::currentPath());
    dirModel.setFilter(QDir::Filter::Drives | QDir::Filter::AllDirs | QDir::Filter::NoDotAndDotDot);

    // Setup the view
    ui->treeView->setModel(&dirModel);

    // Hide all the columns except first column

    for(int i =1; i<dirModel.columnCount();i++)
    {
        ui->treeView->hideColumn(i);
    }

    // Setup the list
    fileModel.setRootPath(dirModel.rootPath());
    fileModel.setFilter(QDir::Filter::Files);
    ui->listView->setModel(&fileModel);
}

