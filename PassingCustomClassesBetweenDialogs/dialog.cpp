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
    QPushButton *button = new QPushButton("Edit",this);
    ui->buttonBox->addButton(button,QDialogButtonBox::ActionRole);
    connect(button,&QPushButton::clicked,this,&Dialog::on_edit);

    album.setBandName("Default");
    album.setAlbumName("Default");
    album.setReleaseDate(QDate(2021,7,8));
    album.setNotes("Default");
    load();
}

void Dialog::load()
{
    ui->plainTextEdit->clear();
    ui->plainTextEdit->setReadOnly(true);

    QString data;
    data.append("Band: " + album.getBandName()+"\r\n");
    data.append("Album: " + album.getAlbumName()+"\r\n");
    data.append("Release: " + album.getReleaseDate().toString() + ("\r\n"));
    data.append("Notes: " + album.getNotes()+"\r\n");
    ui->plainTextEdit->setPlainText(data);
}


void Dialog::on_buttonBox_accepted()
{
    QMessageBox::information(this,"Music",ui->plainTextEdit->toPlainText());
    accept();
}


void Dialog::on_buttonBox_rejected()
{
    reject();
}

void Dialog::on_edit()
{
  Editor *editor = new Editor(this);
  editor->setAlbum(album);
  editor->exec();

  album = editor->getAlbum();
  load();

  delete editor;
}

