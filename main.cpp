#include "mainwindow.h"
#include <QApplication>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QRadioButton>
#include <QSlider>
#include <QSpinBox>
#include <QTextEdit>
#include "changecolor.h"

#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget widget(0);

    QGridLayout grid_layout;
    widget.setLayout(&grid_layout);
    QVBoxLayout v_box_layout;
    QGridLayout gridItems;
    QFormLayout formLayout;

    grid_layout.addLayout(&v_box_layout, 0, 0);
    grid_layout.addLayout(&gridItems,0,1);
    grid_layout.addLayout(&formLayout,1,0);

    QPushButton button1, button2, button3, button4;
    button1.setText("One");
    button2.setText("Two");
    button3.setText("Three");
    button4.setText("Four");
    v_box_layout.addWidget(&button1);
    v_box_layout.addWidget(&button2);
    v_box_layout.addWidget(&button3);
    v_box_layout.addWidget(&button4);

    QPushButton button21, button22, button23, button24,button25;
    button21.setText("One");
    button22.setText("Two");
    button23.setText("Three");
    button24.setText("Four");
    button25.setText("Five");
    gridItems.addWidget(&button21,0,0);
    gridItems.addWidget(&button22,0,1);
    gridItems.addWidget(&button23,1,0,1,2);
    gridItems.addWidget(&button24,2,0);
    gridItems.addWidget(&button25,2,1);

    QPushButton button31, button32, button33, button34;
    QLineEdit textEdit1,textEdit2,textEdit3,textEdit4;
    button31.setText("One");
    button32.setText("Two");
    button33.setText("Three");
    button34.setText("Four");


    formLayout.addRow(&button31,&textEdit1);
    formLayout.addRow(&button32,&textEdit2);
    formLayout.addRow(&button33,&textEdit3);
    formLayout.addRow(&button34,&textEdit4);


    QGridLayout fullGrid;

    QLabel text1,text2,text3;
    QSpinBox spin1,spin2,spin3;
    QSlider slider1,slider2,slider3;

    text1.setText("RED");
    text2.setText("Green");
    text3.setText("Blue");

    spin1.setMaximumWidth(60);
    spin2.setMaximumWidth(60);
    spin3.setMaximumWidth(60);

    spin1.setMaximum(255);
    spin2.setMaximum(255);
    spin3.setMaximum(255);
    slider1.setMaximum(255);
    slider2.setMaximum(255);
    slider3.setMaximum(255);

    fullGrid.addWidget(&text1,0,0);
    fullGrid.addWidget(&text2,1,0);
    fullGrid.addWidget(&text3,2,0);
    fullGrid.addWidget(&spin1,0,1);
    fullGrid.addWidget(&spin2,1,1);
    fullGrid.addWidget(&spin3,2,1);
    slider1.setOrientation(Qt::Orientation::Horizontal);
    slider2.setOrientation(Qt::Orientation::Horizontal);
    slider3.setOrientation(Qt::Orientation::Horizontal);
    fullGrid.addWidget(&slider1,0,2);
    fullGrid.addWidget(&slider2,1,2);
    fullGrid.addWidget(&slider3,2,2);

    QPlainTextEdit editText;

    fullGrid.addWidget(&editText,0,4,3,1);
    QObject::connect(&slider1,SIGNAL(valueChanged(int)),&spin1,SLOT(setValue(int)));
    QObject::connect(&spin1,SIGNAL(valueChanged(int)),&slider1,SLOT(setValue(int)));
    QObject::connect(&slider2,SIGNAL(valueChanged(int)),&spin2,SLOT(setValue(int)));
    QObject::connect(&spin2,SIGNAL(valueChanged(int)),&slider2,SLOT(setValue(int)));
    QObject::connect(&slider3,SIGNAL(valueChanged(int)),&spin3,SLOT(setValue(int)));
    QObject::connect(&spin3,SIGNAL(valueChanged(int)),&slider3,SLOT(setValue(int)));

    grid_layout.addLayout(&fullGrid,3,0);

    ChangeColor color(&editText, &spin1, &spin2, &spin3);
    QObject::connect(&spin1, SIGNAL(valueChanged(int)), &color, SLOT(changedColor()));
    QObject::connect(&spin2, SIGNAL(valueChanged(int)), &color, SLOT(changedColor()));
    QObject::connect(&spin3, SIGNAL(valueChanged(int)), &color, SLOT(changedColor()));

    widget.show();

    return a.exec();
}

