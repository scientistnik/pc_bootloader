#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QSerialPort>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_fresh_com_clicked();
    void on_view_file_clicked();
    void on_start_clicked();
    void programming_time();

private:
    Ui::MainWindow *ui;
    QSerialPort * serial;
    QTimer * timer;
};

#endif // MAINWINDOW_H
