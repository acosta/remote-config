#include "mainwindow.h"
#include "client.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , mClient(new Client())
{
    ui->setupUi(this);
    connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(onQuitButtonClicked()));
    connect(ui->sendButton, SIGNAL(clicked()), this, SLOT(onSendButtonClicked()));
}

MainWindow::~MainWindow()
{
    delete mClient;
    delete ui;
}

void MainWindow::onQuitButtonClicked()
{
    close();
}

void MainWindow::onSendButtonClicked()
{
    ConfigData config;
    config.temperature = ui->tempSpinBox->value();;
    config.velocity = ui->velocSpinBox->value();

    mClient->sendConfig(config);
}

