#include "mainwindow.h"
#include "server.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , mServer(new Server())
{
    ui->setupUi(this);
    connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(onQuitButtonClicked()));
}

MainWindow::~MainWindow()
{
    delete mServer;
    delete ui;
}

void MainWindow::onQuitButtonClicked()
{
    close();
}

