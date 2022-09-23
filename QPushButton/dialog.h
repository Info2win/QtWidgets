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
    void on_btnCheckable_clicked();

    void on_btnAutoRepeat_clicked();

    void on_pushButton_5_clicked();

    void on_btnIsChecked_clicked();

    void on_btnToggleAutoRepeat_clicked();

    void on_btnToggleDefault_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
