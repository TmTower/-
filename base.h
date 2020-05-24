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
    int dmgPerSec=0;
    int dmgArrow=35;
    Base(QGraphicsItem*parent=0);
    void fire(QMouseEvent *event);
public slots:
    void spawn();
};

#endif // BASE_H
