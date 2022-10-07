#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::newFile()
{
    ui->plainTextEdit->clear();
    filename.clear();
    isSaved = false;
    updateStatusBar(filename);
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
        updateStatusBar(filename);
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
    updateStatusBar(filename);
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
    this->setCentralWidget(ui->splitter);
    setupStatusBar();
    newFile();
    isSaved = true;

    for(int i=0; i<301;i++)
    {
        QString item = "Item number: " + QString::number(i);
        ui->listWidget->addItem(item);
    }

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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupStatusBar()
{
    QLabel *lblIcon = new QLabel(this);
    lblIcon->setPixmap(QPixmap(":/icons/images/new.png"));
    ui->statusbar->addWidget(lblIcon);

    QLabel *lblStatus = new QLabel(this);
    lblStatus->setText("Not Saved: ");
    ui->statusbar->addWidget(lblStatus);

    QLabel *lblFile = new QLabel(this);
    lblFile->setText("New");
    ui->statusbar->addWidget(lblFile);
}

void MainWindow::updateStatusBar(QString message)
{
    foreach(QObject* obj,ui->statusbar->children())
    {
        qDebug()<< obj;
    }
 QLabel *lblIcon = qobject_cast<QLabel*>(ui->statusbar->children().at(1));
 QLabel *lblStatus = qobject_cast<QLabel*> (ui->statusbar->children().at(2));
 QLabel *lblFile = qobject_cast<QLabel*>(ui->statusbar->children().at(4));

 if(isSaved)
 {
     lblIcon->setPixmap(QPixmap(":/icons/images/save.png"));
     lblStatus->setText("Saved: ");
 }
 else
 {
     lblIcon->setPixmap(QPixmap(":/icons/images/new.png"));
     lblStatus->setText("Not Saved:");
 }
 lblFile->setText(message);
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



void MainWindow::on_plainTextEdit_textChanged()
{
    isSaved = false;
    if(filename.isEmpty()) updateStatusBar("New File");
    else updateStatusBar(filename);
}


void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    ui->plainTextEdit->appendPlainText(item->text());
}





void MainWindow::on_actionAnimals_triggered()
{
    QStringList options;
    options << "Dog" << "Cat" << "Bird" << "Fish";

    QScopedPointer<Dialog> dialog(new Dialog());
    dialog.data()->setList(options);
    dialog.data()->exec();
    ui->plainTextEdit->insertPlainText(dialog.data()->getSelected());
}


void MainWindow::on_actionShapes_triggered()
{
    QStringList options;
    options << "Oval" << "Circle" << "Triangle" << "Square";

    QScopedPointer<Dialog> dialog(new Dialog());
    dialog.data()->setList(options);
    dialog.data()->exec();
    ui->plainTextEdit->insertPlainText(dialog.data()->getSelected());
}


void MainWindow::on_actionFood_triggered()
{
    QStringList options;
    options << "Pizza" << "Burger" << "Veggie Pizza" << "Steak";

    QScopedPointer<Dialog> dialog(new Dialog());
    dialog.data()->setList(options);
    dialog.data()->exec();
    ui->plainTextEdit->insertPlainText(dialog.data()->getSelected());
}

