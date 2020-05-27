#ifndef BASE_H
#define BASE_H

#include "head_libs.h"

class Base:public QObject,
        public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    int hp=1000;
    int gold=0;
    int dmgPerSec1=0;
    int dmgPerSec2=0;
    int dmgArrow=35;
    bool open1=false;
    bool open2=false;
    Base(QGraphicsItem*parent=0);
    void fire(QMouseEvent *event);
public slots:
    void spawn();
};

#endif // BASE_H
