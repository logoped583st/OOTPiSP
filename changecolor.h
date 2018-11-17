#ifndef CHANGECOLOR_H
#define CHANGECOLOR_H

#include <QPlainTextEdit>
#include <QSpinBox>
#include <QTextEdit>



class ChangeColor : public QObject{
    Q_OBJECT


private: QPlainTextEdit *editText;
         QSpinBox *spin1,*spin2,*spin3;

public: ChangeColor(QPlainTextEdit *editText,QSpinBox *spin1,QSpinBox *spin2,QSpinBox *spin3);

public slots:
         void changedColor();
};

#endif // CHANGECOLOR_H

