#include "figure.h"

#include <QTimer>

Figure::Figure(QWidget *parent)
    : QWidget(parent)
{
    resize(_width, _height);
    setMinimumWidth(_width);
    setMinimumHeight(_height);

    QTimer* timer = new QTimer();
    timer->setInterval(_timeMS);
    timer->start();
    connect(timer, SIGNAL(timeout()), SLOT(update()));
}

void Figure::paintEvent(QPaintEvent *)
{
    QFont font("URW Gothic L,11,-1,5,63,2,0,0,0,0");
    setFont(font);

    QPainter painter(this);
    painter.setPen(Qt::black);
    painter.rotate(90);
    painter.drawText(height() / 2, -width() / 2, "Laboratory work 11");
    drawSnowFlake((geometry().width() - _width) / 2 + _width / 2 + _x,
                  (geometry().height() - _height) / 2 + _height / 2 + _y);
    nextPoint();
}

void Figure::drawSnowFlake(int x, int y)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(QPen(Qt::darkBlue, 1, Qt::SolidLine, Qt::RoundCap));


    painter.drawLine(QLineF(x+5,y+5,x-_radius/2,y-_radius/2));
    painter.drawLine(QLineF(x+_radius,y+_radius,x+_radius/2-5,y+_radius/2-5));
    painter.drawLine(QLineF(x+_radius/2,y+7,x+_radius,y-_radius/2));
    painter.drawLine(QLineF(x+7,y+_radius/2-7,x-_radius/2+3,y+_radius));


    painter.drawLine(QLineF(x,y+_radius/4,x-_radius-10,y+_radius/4));
    painter.drawLine(QLineF(x+_radius/2,y+_radius/4,x+1.5*_radius+10,y+_radius/4));

    painter.drawLine(QLineF(x+_radius/4, y ,x + _radius/4, y-_radius));

    painter.drawLine(QLineF(x+_radius/4, y+_radius/2 ,x + _radius/4, y+1.5*_radius));

    painter.drawEllipse(x, y , _radius / 2, _radius / 2);
}

void Figure::drawPartOfSnowflake(int x1, int y1, int x2, int y2, int number)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(QPen(Qt::darkBlue, 1, Qt::SolidLine, Qt::RoundCap));

    double angle = 60 * 3.14 / 180;
    int x3 = (2 * x1 + x2) / 3;
    int y3 = (2 * y1 + y2) / 3;

    int x4 = (x1 + 2 * x2) / 3;
    int y4 = (y1 + 2 * y2) / 3;

    int x = (x3 + (x4 - x3) * cos(angle) + (y4 - y3) * sin(angle));
    int y = (y3 - (x4 - x3)  *sin(angle) + (y4 - y3) * cos(angle));

    if(number > 0)
    {
        drawPartOfSnowflake(x1, y1, x3, y3, number - 1);
        drawPartOfSnowflake(x3, y3, x, y, number - 1);
        drawPartOfSnowflake(x, y, x4, y4, number - 1);
        drawPartOfSnowflake(x4, y4, x2, y2, number - 1);
    }
    else
    {
        painter.drawLine(x1, y1, x3, y3);
        painter.drawLine(x3, y3, x, y);
        painter.drawLine(x, y, x4, y4);
        painter.drawLine(x4, y4, x2, y2);
    }
}

void Figure::nextPoint()
{
    _theta = (_theta + 1) % 365;
    double r = sin(3.14 / 180. * _n * _theta);

    _x =(r * cos(3.14 / 180. * _theta) * (_width / 2 - _radius));
    _y =(r * sin(3.14 / 180. * _theta) * (_height / 2 - _radius));
}
