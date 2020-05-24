#include "game.h"
#include "enemy.h"


Game::Game(QWidget *parent)
{
    scene = new QGraphicsScene;
    scene->setSceneRect(0,0,800,600);
    //setBackgroundBrush(QBrush(QImage(""))); //выбор заднего фона
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);
    setMouseTracking(true);
    base= new Base();
    base->setPos(400,500);//нужно будет отколибровать по центру
    base->setFlag(QGraphicsItem::ItemIsFocusable);
    base->setFocus();

    scene->addItem(base);
    score= new Score();
    scene->addItem(score);

    QTimer *timer = new QTimer;
    connect(timer, SIGNAL(timer), base, SLOT(spawn()));
    timer->start(2000);

    show();

}
