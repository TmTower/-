#include "base.h"
#include "enemy.h"
#include "bullet.h"
#include "game.h"

extern Game*game;

Base::Base(QGraphicsItem *parent):
    QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/new/prefix1/imagines/basa.jpg"));
}


void Base::spawn()
{
    Enemy * enemy = new Enemy();
    enemy->setPos(game->scene->width(), game->scene->height());
    scene()->addItem(enemy);
    game->enym.push_back(enemy);//массив в нутри которого лежат ссылки на врагов

}

void Base::fire(QMouseEvent *event)
{
    Bullet *bul= new Bullet();
    bul->setPos(x(),y());
    scene()->addItem(bul);
    game->bul.push_back(bul);//массив в нутри которого хранятся сылки на все снаряды

}
