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
    quint16 temperature = ui->tempSpinBox->value();
    quint16 velocity = ui->velocSpinBox->value();

    mClient->sendConfig(temperature, velocity);
}

