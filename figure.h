#ifndef FIGURE_H
#define FIGURE_H

#include <math.h>

#include <QPainter>
#include <QWidget>

class Figure : public QWidget
{
    Q_OBJECT

public:
    explicit Figure(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent*) override;

private:
    void drawSnowFlake(int x, int y);
    void drawPartOfSnowflake(int x1, int y1, int x2, int y2, int number);
    void nextPoint();

private:
    const int _timeMS = 30; // for speed
    const int _radius = 75; // size of snowflake
    const int _number = 2; // ~1-3
    const int _width = 500;
    const int _height = 500;
    int _x = 0;
    int _y = 0;

    int _theta = 0;
    int _n = 3; // change it from 1 to 7
};

#endif // FIGURE_H
