#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "actions.h"
#include <QDebug>
#include <QtGlobal>
#include <algorithm>
#include <vector>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
      numsB = findChildren<QPushButton *>();

    num = new class actions(this);
    ui->setupUi(this);

    connect(ui->Pb_0, SIGNAL(clicked()), this, SLOT(didget_numbers()));
    connect(ui->Pb_1, SIGNAL(clicked()), this, SLOT(didget_numbers()));
    connect(ui->Pb_2, SIGNAL(clicked()), this, SLOT(didget_numbers()));
    connect(ui->Pb_3, SIGNAL(clicked()), this, SLOT(didget_numbers()));
    connect(ui->Pb_4, SIGNAL(clicked()), this, SLOT(didget_numbers()));
    connect(ui->Pb_5, SIGNAL(clicked()), this, SLOT(didget_numbers()));
    connect(ui->Pb_6, SIGNAL(clicked()), this, SLOT(didget_numbers()));
    connect(ui->Pb_7, SIGNAL(clicked()), this, SLOT(didget_numbers()));
    connect(ui->Pb_8, SIGNAL(clicked()), this, SLOT(didget_numbers()));
    connect(ui->Pb_9, SIGNAL(clicked()), this, SLOT(didget_numbers()));

    connect(ui->Pb_plus, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->plusMinus, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->Pb_minus, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->Pb_l, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->Pb_x, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->Pb_k, SIGNAL(clicked()), this, SLOT(operations()));

    connect(ui->leftS, SIGNAL(clicked()), this, SLOT(stapels()));
    connect(ui->rightS, SIGNAL(clicked()), this, SLOT(stapels()));

    connect(ui->Pb_prot, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->Pb_step, SIGNAL(clicked()), this, SLOT(operations()));

    connect(this, &MainWindow::sign, num, &actions::SetExpression);
    connect(this, &MainWindow::ruvn, num, &actions::ruvn);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::didget_numbers() {
    Num = 0;
    qDebug() << "test has gone";
    QPushButton *button = (QPushButton *)sender();
    emit sign(button->text(), Num++);
    Num = 0;
}

void MainWindow::stapels()
{
    QPushButton *button = (QPushButton *)sender();

    if (button->text() == "(") {
    if (Num == 1 && close != 1) {
        close = 1;
         emit sign(button->text());
      }
    }

    if (button->text() == ")") {
    if (Num == 0 && close == 1) {
        close = 0;
         emit sign(button->text());
      }
    }
}

void MainWindow::on_Pb_tochka_clicked()
{
    if(lastOpp) {
    iter = ::find(lastOpp, num->expression.end(), '.');
    if (iter != num->expression.end()) {exit(1);} }
    QPushButton *button = (QPushButton *)sender();
    QChar a = *(num->expression.end() - 2);
    if(Num == 0 && a != button->text()) {
    emit sign(button->text(), Num++);
  }
}

void MainWindow::operations() {
    QPushButton *button = (QPushButton *)sender();
        if (Num == 0) {
     emit sign(button->text(), Num++);
        lastOpp = 0;
        lastOpp = num->expression.end() - 1;
      }
}

void MainWindow::on_Pb_backspace_clicked()
{

}

void MainWindow::on_Pb_ruvn_clicked()
{
   emit ruvn();
}
