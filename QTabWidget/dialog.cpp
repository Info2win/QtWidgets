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

void Dialog::hrClicked()
{
    QMessageBox::information(this,"HR","You sent the info to HR");
}

void Dialog::legalClicked()
{
    QMessageBox::information(this,"Legal","You sent the info to Legal");
}

void Dialog::nextClicked()
{
    int tab = ui->tabWidget->currentIndex();
    int max = ui->tabWidget->count()-1;
    tab++;
    if(tab > max) tab = max;
    ui->tabWidget->setCurrentIndex(tab);
}

void Dialog::backClicked()
{
    int tab = ui->tabWidget->currentIndex();
    const int min = 0;
    tab--;
    if(tab < min) tab = min;
    ui->tabWidget->setCurrentIndex(tab);
}

void Dialog::init()
{
    // Construct buttons
    QPushButton *btnBack = new QPushButton("Back",this);
    QPushButton *btnNext = new QPushButton("Next",this);
    // Connect buttons signals' to slots
    connect(btnBack,&QPushButton::clicked,this,&Dialog::backClicked);
    connect(btnNext,&QPushButton::clicked,this,&Dialog::nextClicked);
    // Put buttons to the buttonBox
    ui->buttonBox->addButton(btnBack,QDialogButtonBox::ActionRole);
    ui->buttonBox->addButton(btnNext,QDialogButtonBox::ActionRole);
    // Update the tabs
    ui->tabWidget->setTabText(0,"Profile");
    ui->tabWidget->setTabText(1,"Notes");
    // Add a new tab dynamically
    QWidget *widget = new QWidget(this);
    ui->tabWidget->addTab(widget,"Send");
    // Fill the tab
    QPushButton *btnHr = new QPushButton("Send to HR",this);
    QPushButton *btnLegal = new QPushButton ("Send to Legal",this);
    connect(btnHr,&QPushButton::clicked,this,&Dialog::hrClicked);
    connect(btnLegal,&QPushButton::clicked,this,&Dialog::legalClicked);
    // Set vertical box layout dynamically
    QVBoxLayout * vlayout = new QVBoxLayout(widget);
    vlayout->addWidget(btnHr);
    vlayout->addWidget(btnLegal);
    widget->setLayout(vlayout);
}

























