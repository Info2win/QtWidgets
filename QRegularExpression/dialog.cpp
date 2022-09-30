#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QRegularExpression rx("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b",QRegularExpression::CaseInsensitiveOption);
    ui->txtEmail->setValidator(new QRegularExpressionValidator(rx,this));
    connect(ui->txtEmail,&QLineEdit::textChanged,this,&Dialog::checkEmailInput);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::checkEmailInput()
{
    if(ui->txtEmail->hasAcceptableInput())
        ui->txtEmail->setStyleSheet("QLineEdit {color:black;}");
    else
        ui->txtEmail->setStyleSheet("QLineEdit {color:red;}");

}


void Dialog::on_buttonBox_accepted()
{
   if(ui->txtEmail->hasAcceptableInput())
   {
       QMessageBox::information(this,"Email",ui->txtEmail->text());
       accept();
   }
   else QMessageBox::critical(this,"Email","Email is not valid!");
}
void Dialog::on_buttonBox_rejected()
{
    reject();
}

