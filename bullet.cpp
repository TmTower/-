#include "bullet.h"
#include "enemy.h"
#include "game.h"

extern Game*game;


Bullet::Bullet(QGraphicsItem*parent):
    QObject(),QGraphicsPixmapItem(parent)
{
    //setPixmap(QImage(""));    //выбираем рисунок снаряда
    QTimer *timer= new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}


void Bullet::move()
{

     for (int i=0;i<game->enym.size();i++)//проходим по массиву врагов
     {
         if (abs(this->pos().x()-game->enym[i].pos().x())<10 and abs(this->pos().y()-game->enym[i].pos().y())<10)//если есть "коллизия"
         {
             game->enym[i].hp-=game->base->dmgArrow;//уменьшаем хп врага
             if (game->enym[i].hp<=0)//если хп врага меньше/равно 0
             {
                 game->base->gold+=game->enym[i].cost;//получаем золото
                 game->score->goldIncrease(game->enym[i].cost);//увеличиваем score
                 scene()->removeItem(game->enym[i]);//удаляем со сцены врага
                 delete game->enym[i];//удаляем врага
                 game->enym.erase(game->enym.begin()+i);//удаляем врага из массива
                 scene()->removeItem(this);//удаляем со сцены снаряд
                 delete this;//удаляем снаряд
                 return;//выходим
             }
         }
     }



    QMouseEvent *ev;//стрельба по прямой
    int x2=ev->pos().x();
    int y2=ev->pos().y();
    setPos(x()+10,y()-10*double(y2-500)/double(x2-400));

    if (this->pos().x()>=game->scene->width() or this->pos().y()<=0 or this->pos().y()>=game->scene->height() or this->pos().x()<=0)//проверяем , вышел ли снаряд за пределы экрана и если да - удаляем его
    {
        scene()->removeItem(this);
        delete this;
    }
}
