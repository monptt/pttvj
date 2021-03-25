#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore/QDebug>

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

