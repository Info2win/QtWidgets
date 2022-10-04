#ifndef EDITOR_H
#define EDITOR_H

#include <QDialog>
#include "album.h"

namespace Ui {
class Editor;
}

class Editor : public QDialog
{
    Q_OBJECT

public:
    explicit Editor(QWidget *parent = nullptr);
    ~Editor();

    const Album &getAlbum() const;
    void setAlbum(const Album &newAlbum);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Editor *ui;
    Album album;
};

#endif // EDITOR_H
