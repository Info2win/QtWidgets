#ifndef DIALOG2_H
#define DIALOG2_H

#include <QDialog>
#include <QDir>
#include <QFile>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QFileInfoList>
#include <QListWidgetItem>

namespace Ui {
class Dialog2;
}

class Dialog2 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog2(QWidget *parent = nullptr);
    ~Dialog2();
    QString selected();
    void setSelected(QString selected);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Dialog2 *ui;

    QString selectedIcon;
    void init();

};

#endif // DIALOG2_H
