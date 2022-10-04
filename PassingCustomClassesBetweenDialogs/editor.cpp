#include "editor.h"
#include "ui_editor.h"

Editor::Editor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Editor)
{
    ui->setupUi(this);
}

Editor::~Editor()
{
    delete ui;
}

void Editor::on_buttonBox_accepted()
{
    album.setAlbumName(ui->txtAlbum->text());
    album.setBandName(ui->txtBand->text());
    album.setReleaseDate(ui->dtRelease->date());
    album.setNotes(ui->ptxtNotes->toPlainText());
    accept();
}


void Editor::on_buttonBox_rejected()
{
    reject();
}

const Album &Editor::getAlbum() const
{
    return album;
}

void Editor::setAlbum(const Album &newAlbum)
{
    album = newAlbum;

    ui->txtBand->setText(album.getBandName());
    ui->txtAlbum->setText(album.getBandName());
    ui->dtRelease->setDate(album.getReleaseDate());
    ui->ptxtNotes->setPlainText(album.getNotes());
}

