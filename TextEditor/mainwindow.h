#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private slots:
    void newFile();
    void openFile();
    void saveFile();
    void saveFileAs();
    void selectNone();
    void on_actionTop_triggered();

    void on_actionBottom_triggered();

    void on_actionLeft_triggered();

    void on_actionRight_triggered();

    void on_actionFloatable_toggled(bool arg1);

    void on_actionMovable_toggled(bool arg1);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString filename;
    bool isSaved;
};
#endif // MAINWINDOW_H
