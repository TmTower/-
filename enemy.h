#ifndef ENEMY_H
#define ENEMY_H

#include "head_libs.h"

class Enemy: public QObject,
        public QGraphicsPixmapItem
{
    Q_OBJECT;
public:
    int hp=500;
    int speed=10;
    int cost=100;
    Enemy(QGraphicsItem*parent=0);
public slots:
    void move();
};

#endif // ENEMY_H
