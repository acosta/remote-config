#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(onQuitButtonClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onQuitButtonClicked()
{
    close();
}

