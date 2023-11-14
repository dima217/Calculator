#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    int number = 0;
    QString opperation;
    double all_numbers[2];
    double result;


private slots:
    void didget_numbers();
    void on_Pb_tochka_clicked();
    void operations();
    void on_Pb_ruvn_clicked();
};
#endif // MAINWINDOW_H
