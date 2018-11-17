#include "changecolor.h"

#include <QPlainTextEdit>

ChangeColor::ChangeColor(QPlainTextEdit *editText, QSpinBox *spin1, QSpinBox *spin2, QSpinBox *spin3){
    this->spin1 = spin1;
    this->spin2 = spin2;
    this->spin3 = spin3;
    this->editText=editText;
}


void ChangeColor::changedColor(){
    QString styles=QString("QPlainTextEdit{background-color:#%1%2%3}").arg(this->spin1->value(), 2,16,QLatin1Char('0'))
            .arg(this->spin2->value(),2,16,QLatin1Char('0')).arg(this->spin3->value(),2,16,QLatin1Char('0'));
    this->editText->setStyleSheet(styles);
}
