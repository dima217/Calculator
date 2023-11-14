#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QtGlobal>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
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

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::didget_numbers() {

    QPushButton *button = (QPushButton *)sender();

    all_numbers[number] = (ui->Result_Show->text() + button->text()).toDouble();
     qDebug() << all_numbers[number];
     qDebug() << number;
     QString text_numbers = QString::number(all_numbers[number], 'g', 15);
    ui->Result_Show->setText(text_numbers);
}

void MainWindow::on_Pb_tochka_clicked()
{

    if(!ui->Result_Show->text().contains('.'))
    ui->Result_Show->setText(ui->Result_Show->text() + ".");

}
void MainWindow::operations() {

    QPushButton *button = (QPushButton *)sender();

    if (button->text() == "AC") {
        number = 0;
        all_numbers[0] = 0;
        all_numbers[1] = 0;
        ui->Result_Show->setText("0");

    }

    if (button->text() == "+/-") {
    all_numbers[number] = (ui->Result_Show->text()).toDouble();
    all_numbers[number] = all_numbers[number] * -1;
    QString text_numbers = QString::number(all_numbers[number], 'g', 10);
    ui->Result_Show->setText(text_numbers);

    }

    if (button->text() == "+" || button->text() == "-" || button->text() == "x" || button->text() == "/") {
        number = 1;
        opperation = button->text();
        qDebug() << opperation;
        ui->Result_Show->setText("0");
    }
}

void MainWindow::on_Pb_ruvn_clicked()
{
    qDebug() << opperation;
    number = 0;
    if (opperation == "+") {all_numbers[number] = all_numbers[0] + all_numbers[1]; }
    if (opperation == "-") {all_numbers[number] = all_numbers[0] - all_numbers[1]; }
    if (opperation == "/") { all_numbers[number] = all_numbers[0] / all_numbers[1]; }
    if (opperation == "x") { all_numbers[number] = all_numbers[0] * all_numbers[1]; }
    qDebug() << all_numbers[number];

    QString text_numbers = QString::number(all_numbers[number], 'g', 10);
   ui->Result_Show->setText(text_numbers);
}
