#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <actions.h>
#include <QPushButton>
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; class QLabel; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    class actions *num {};
    class actions *act {};
    QList<QPushButton*>numsB;
    int Num;
    int close;
    QChar *lastOpp = 0;
    QString::iterator iter;

signals:

    void sign(QString labl, int CheckOpp = 0);
    void ruvn();

private slots:
    void didget_numbers();
    void stapels();
    void on_Pb_tochka_clicked();
    void operations();
    void on_Pb_backspace_clicked();
    void on_Pb_ruvn_clicked();
};
#endif // MAINWINDOW_H
