#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    ui->chkEnabled->setChecked(ui->txtTest->isEnabled());
    ui->chkReadOnly->setChecked(ui->txtTest->isReadOnly());
    ui->chkClearButton->setChecked(ui->txtTest->isClearButtonEnabled());

    QMetaEnum metanum = QMetaEnum::fromType<QLineEdit::EchoMode>();

    for(int i=0; i<metanum.keyCount();i++)
    {
        ui->comboBox->addItem(metanum.valueToKey(i),metanum.value(i));
    }
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_txtDefault_textChanged(const QString &arg1)
{
    ui->txtTest->setText(arg1);
}


void Dialog::on_comboBox_currentIndexChanged(int index)
{
    QMetaEnum metanum = QMetaEnum::fromType<QLineEdit::EchoMode>();
    int value = metanum.keyToValue(ui->comboBox->currentText().toLocal8Bit().data());
    ui->txtTest->setEchoMode(static_cast<QLineEdit::EchoMode>(value));
}


void Dialog::on_chkEnabled_toggled(bool checked)
{
    ui->txtTest->setEnabled(checked);
}


void Dialog::on_chkReadOnly_toggled(bool checked)
{
    ui->txtTest->setReadOnly(checked);
}


void Dialog::on_chkClearButton_toggled(bool checked)
{
    ui->txtTest->setClearButtonEnabled(checked);
}

