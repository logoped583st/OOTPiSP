#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMath>
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setRowCount(19);
    QStringList headers;
    headers.append("Градусы");
    headers.append("Радианы");
    headers.append("Результат");
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->setStyleSheet("QTableWidget {background-color: rgb(255, 255, 255); selection-background-color: rgb(0, 0, 0); }");
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    setTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setTable(){
    for(int i=0; i<20;i++){
        QTableWidgetItem *newItemRad = new QTableWidgetItem(tr("%1").arg(i*5*M_PI/180));
        newItemRad->setBackgroundColor(Qt::black);
        QTableWidgetItem *newItemDegree=new QTableWidgetItem(tr("%1").arg(i*5));
        newItemDegree->setBackgroundColor(Qt::black);
        ui->tableWidget->setItem(i,0,newItemDegree);
        ui->tableWidget->setItem(i,1,newItemRad);
    }
}

void MainWindow::calculate(int func){
    for(int i=0; i<19;i++){
        qDebug()<<ui->tableWidget->item(i,1)->text().toDouble();
        ui->tableWidget->setItem(i,2,calculateItem(func,ui->tableWidget->item(i,1)->text().toDouble()));
    }
}

QTableWidgetItem* MainWindow::calculateItem(int func, double grad){
    QTableWidgetItem *newItem;
    switch (func) {
        case sin: {
            newItem = new QTableWidgetItem(tr("%1").arg(qSin(grad)));
            newItem->setData(0x03, "Guess what?"); // <- this will be the tooltip text("asdasd");

            break;
        }

        case cos:{
            newItem = new QTableWidgetItem(tr("%1").arg(qCos(grad)));
            break;
        }
        case tg:{
            newItem = new QTableWidgetItem(tr("%1").arg(qTan(grad)));
            break;
        }
    }
    newItem->setBackgroundColor(Qt::black);
   // newItem->setToolTip(newItem->text());
    return newItem;
}



void MainWindow::on_cos_clicked()
{
    calculate(this->cos);
}

void MainWindow::on_sin_clicked()
{
    calculate(this->sin);
}

void MainWindow::on_tg_clicked()
{
    calculate(this->tg);
}
