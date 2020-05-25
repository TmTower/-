#include "btn.h"
#include "base.h"
#include "game.h"

extern Game*game;

Btn::Btn(QGraphicsItem*parent):
    QPushButton()
{
}

void Btn::get(int c, string n)
{
    this->name=n;//получили данные каждой кнопки
    this->cost=c;
    this->setText(QString::fromUtf8((this->name).c_str())+'\n'+QString::fromUtf8(to_string(this->cost).c_str()));
}

void Btn::chek()
{
    if (this->name=="arrow damage")
        this->arUp();
    else if (this->name=="minion 1 unlock")
        this->min1Un();
    else if (this->name =="minion 1 damage")
        this->min1Up();
    else if (this->name=="minion 2 unlock")
        this->min2Un();
    else if (this->name=="minion 2 damage")
        this->min2Up();
}

void Btn::arUp()
{
    if (game->base->gold-300>=0)
    {
        game->base->gold-=300;
        game->base->dmgArrow+=25;
    }
}

void Btn::min1Un()
{
    if (game->base->open1==false)
    {
        if (game->base->gold-1500>=0)
        {
            //нужно чтобы появилась фигурка лучника на башне
            game->base->open1=true;
            game->base->dmgPerSec1=5;
            game->base->gold-=1500;
        }
    }
}

void Btn::min1Up()
{
    if (game->base->open1==true)
    {
        if (game->base->gold-500>=0)
        {
            game->base->dmgPerSec1+=15;
            game->base->gold-=500;
        }
    }
}

void Btn::min2Un()
{
    if (game->base->open2==false)
    {
        if (game->base->gold-10000>=0)
        {
            //нужно чтобы появлялся маг на башне
            game->base->open2=true;
            game->base->dmgPerSec2=100;
            game->base->gold-=10000;
        }
    }
}

void Btn::min2Up()
{
    if (game->base->open2==true)
    {
        if (game->base->gold-1500>=0)
        {
            game->base->gold-=1500;
            game->base->dmgPerSec2+=50;
        }
    }
}
