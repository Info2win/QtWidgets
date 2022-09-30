#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QIcon>
QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;
    void load();
    void save();
    bool isSaved;

    // QWidget interface
protected:
    void closeEvent(QCloseEvent *event);
private slots:
    void on_btnNew_clicked();
    void on_btnOpen_clicked();
    void on_btnSave_clicked();
    void special_accept();
    void on_plainTextEdit_textChanged();
};
#endif // DIALOG_H
