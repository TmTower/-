#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "game.h"
#include "head_libs.h"


Game *game;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_start_clicked()
{
    game=new Game();
    game->show();
}
