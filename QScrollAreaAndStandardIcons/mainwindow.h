#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QStyle>
#include <QLabel>
#include <QFileDialog>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private slots:

    void on_actionOpen_triggered();

    void on_actionZoom_In_triggered();

    void on_actionZoom_Out_triggered();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QLabel* lblImage;
    QString path;
    QPixmap img;
};
#endif // MAINWINDOW_H
