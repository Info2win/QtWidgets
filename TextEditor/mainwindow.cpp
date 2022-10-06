#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::newFile()
{
    ui->plainTextEdit->clear();
    filename.clear();
    isSaved = false;
    ui->statusbar->showMessage("New File");
}

void MainWindow::openFile()
{
    QString temp = QFileDialog::getOpenFileName(this,"Open a File",QString(),"Text Files(*txt);;All Files(*,*");
    if(temp.isEmpty()) return;
    filename = temp;
    QFile file(filename);
        if(!file.open(QIODevice::ReadOnly))
        {
            newFile();
            QMessageBox::critical(this,"Error", file.errorString());
            return;
        }

        QTextStream stream(&file);
        ui->plainTextEdit->setPlainText(stream.readAll());
        file.close();

        isSaved = true;
        ui->statusbar->showMessage(filename);
}

void MainWindow::saveFile()
{
    if(filename.isEmpty())
    {
        saveFileAs();
        return;
    }

    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::critical(this,"Error", file.errorString());
        return;
    }

    QTextStream stream(&file);
    stream << ui->plainTextEdit->toPlainText();
    file.close();

    isSaved = true;
    ui->statusbar->showMessage(filename);
}

void MainWindow::saveFileAs()
{
    QString temp = QFileDialog::getSaveFileName(this,"Save File",QString(),"Text Files (*txt);;All Files (*,*)");
    if(temp.isEmpty()) return;
    filename = temp;
    saveFile();
}

void MainWindow::selectNone()
{
    QTextCursor cursor = ui->plainTextEdit->textCursor();
    int pos = cursor.position();
    cursor.clearSelection();
    cursor.setPosition(pos,QTextCursor::MoveMode::KeepAnchor);
    ui->plainTextEdit->setTextCursor(cursor);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->plainTextEdit);
    newFile();
    isSaved = true;
    // File
    connect(ui->actionNew,&QAction::triggered,this,&MainWindow::newFile);
    connect(ui->actionOpen,&QAction::triggered,this,&MainWindow::openFile);
    connect(ui->actionSave, &QAction::triggered,this, &MainWindow::saveFile);
    connect(ui->actionSave_As, &QAction::triggered,this, &MainWindow::saveFileAs);
    connect(ui->actionExit, &QAction::triggered,this, &MainWindow::close);
    // Edit
    connect(ui->actionCopy,&QAction::triggered,ui->plainTextEdit,&QPlainTextEdit::copy);
    connect(ui->actionCut,&QAction::triggered,ui->plainTextEdit,&QPlainTextEdit::cut);
    connect(ui->actionPaste,&QAction::triggered,ui->plainTextEdit,&QPlainTextEdit::paste);
    connect(ui->actionSelect_All,&QAction::triggered,ui->plainTextEdit,&QPlainTextEdit::selectAll);
    connect(ui->actionSelect_None, &QAction::triggered,this, &MainWindow::selectNone);
    // Toolbar View

    // Insert

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionTop_triggered()
{
    addToolBar(Qt::ToolBarArea::TopToolBarArea,ui->toolBar);
}


void MainWindow::on_actionBottom_triggered()
{
    addToolBar(Qt::ToolBarArea::BottomToolBarArea,ui->toolBar);
}


void MainWindow::on_actionLeft_triggered()
{
    addToolBar(Qt::ToolBarArea::LeftToolBarArea,ui->toolBar);
}


void MainWindow::on_actionRight_triggered()
{
    addToolBar(Qt::ToolBarArea::RightToolBarArea,ui->toolBar);
}


void MainWindow::on_actionFloatable_toggled(bool arg1)
{
    ui->toolBar->setFloatable(arg1);
}


void MainWindow::on_actionMovable_toggled(bool arg1)
{
    ui->toolBar->setMovable(arg1);
}


