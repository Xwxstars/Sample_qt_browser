#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QNetworkProxyFactory>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("shark-browser");
    setWindowIcon(QIcon(":/shark.png"));
    QNetworkProxyFactory::setUseSystemConfiguration(false);
    myweb=new Mywebengine(this);
    ui->verticalLayout->addWidget(myweb);
    myweb->load(QUrl("https://www.bing.com"));


}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::resizeEvent(QResizeEvent* event){
    this->myweb->resize(this->size());
}




void MainWindow::on_actionforward_triggered()
{
    myweb->forward();
}

void MainWindow::on_actionback_triggered()
{
    myweb->back();
}
