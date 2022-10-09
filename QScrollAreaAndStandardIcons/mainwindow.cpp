#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Standart icons
    ui->actionOpen->setIcon(QApplication::style()->standardIcon(QStyle::SP_DialogOpenButton));
    ui->actionZoom_In->setIcon(QApplication::style()->standardIcon(QStyle::SP_ArrowUp));
    ui->actionZoom_Out->setIcon(QApplication::style()->standardIcon(QStyle::SP_ArrowDown));

    // Initialize lblImage
    lblImage = new QLabel(this);
    ui->scrollArea->setWidget(lblImage);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionOpen_triggered()
{
    path = QFileDialog::getOpenFileName(this,"Open an Image",QString(),"All Files(*.*);;JPG(*.jpg);;PNG(*png)");
    if(path.isEmpty()) return;
    if(!img.load(path))
    {
        QMessageBox::critical(this,"Error","Could not load the image!");
        return;
    }
    lblImage->setPixmap(img);
}


void MainWindow::on_actionZoom_In_triggered()
{
    int w = lblImage->width();
    int h = lblImage->height();

    w+=10;
    h+=10;

    if(w < 10) w = 10;
    if(h < 10) h = 10;

    lblImage->resize(w,h);
    lblImage->setPixmap(img.scaled(w,h));

}


void MainWindow::on_actionZoom_Out_triggered()
{
    int w = lblImage->width();
    int h = lblImage->height();

    w -= 10;
    h -=10;

    if(w < 10) w = 10;
    if(h < 10) h = 10;

    lblImage->resize(w,h);
    lblImage->setPixmap(img.scaled(w,h));

}

