#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QList>
#include <QRadioButton>

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
    void on_btnOK_clicked();

    void on_btnCancel_clicked();
    QString getOption(QObject *obj);

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
