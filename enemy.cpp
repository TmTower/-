#include "enemy.h"
#include "game.h"
#include "base.h"

extern Game * game;

Enemy::Enemy(QGraphicsItem*parent):QObject(),
    QGraphicsPixmapItem(parent)
{
    setPos(game->scene->width(),game->scene->height());
    //setPixmap()   //здесь должна выбираться картинка врага
    QTimer * timer= new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move));
    timer->start(100);
}

void Enemy::move()
{
    setPos(x()-speed,y());
    if (pos().y()>600)  //удаляем врага с экрана если он вышел за границы
    {
        game->base->hp-=100;
        scene()->removeItem(this);
        delete this;
    }
}
