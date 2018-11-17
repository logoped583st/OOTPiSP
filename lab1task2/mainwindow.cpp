#include "mainwindow.h"

#include <QFile>
#include <QFileDialog>
#include <QGridLayout>
#include <qtextstream.h>
#include <QPushButton>



MainWindow::MainWindow(QWidget *parent): QWidget(parent){
    createInterface();
    QGridLayout *grid=new QGridLayout;
    grid->addWidget(open_button,0,0);
    grid->addWidget(text_edit,1,0);
    setLayout(grid);
    connectWidgets();
}

void MainWindow::createInterface(){
    open_button = new QPushButton("Open file");
    text_edit = new QTextEdit();
    text_edit->setReadOnly(true);
}

void MainWindow::connectWidgets(){
    connect(open_button,SIGNAL(clicked(bool)),SLOT(openFile()));
}

void MainWindow::openFile(){
    QString fileName=QFileDialog::getOpenFileName();
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
        return;
    QTextStream stream(&file);
    QString data=stream.readAll();
    text_edit->setText(data);
}
MainWindow::~MainWindow(){}
