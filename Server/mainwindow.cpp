#include "mainwindow.h"
#include "server.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , mServer(new Server())
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete mServer;
    delete ui;
}

void MainWindow::on_quitButton_clicked()
{
    close();
}

