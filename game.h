#ifndef GAME_H
#define GAME_H

#include "head_libs.h"
#include "base.h"
#include "score.h"
#include "enemy.h"
#include "bullet.h"

class Game: public QGraphicsView
{
public:
    Game(QWidget *parent=0);
    //vector<Enemy>enym;
    //vector<Bullet>bul;
    QGraphicsScene *scene;
    Base *base;
    Score *score;


    QSqlDatabase DB;
    QSqlQuery query;
    QString pathDB;
};

#endif // GAME_H
