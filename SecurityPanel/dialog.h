#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_btnSave_clicked();

    void on_btnVerify_clicked();

private:
    Ui::Dialog *ui;
    QString temp,code;
    void append();

};
#endif // DIALOG_H
