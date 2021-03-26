#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore/QDebug>
#include <QMovie>
// コンストラクタ
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qDebug() << "MainWindow start";

}

// デストラクタ
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_cmdBtn_clicked()
{
    QString str = ui->cmdLine->text();
    ui->cmdLine->clear();
    qDebug() << str;
}

void MainWindow::on_cmdLine_returnPressed()
{
    QString str = ui->cmdLine->text();
    ui->cmdLine->clear();
    qDebug() << str;
}
