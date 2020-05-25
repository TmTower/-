#include "game.h"
#include "enemy.h"
#include "btn.h"


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
    base->setPos(0, scene->height());//нужно будет отколибровать сбоку
    base->setFlag(QGraphicsItem::ItemIsFocusable);
    base->setFocus();

    this->DB=QSqlDatabase::addDatabase("QSQLITE");
    this->DB.setDatabaseName("C:/Users/Андрей/Desktop/Shop.db");

    if (this->DB.open())
    {
        this->query=QSqlQuery(this->DB);
        this->query.exec("CREATE TABLE IF NOT EXISTS buys (name TEXT, price INT)");
        int i=0;
        while (this->query.next())
        {
            string name=this->query.value(0).toString().toUtf8().constData();
            int cost=this->query.value(1).toString().toInt();
            Btn *btn=new Btn();//создали кнопку, присвоили ей значения и расположил на экране
            btn->get(cost, name);
            btn->setGeometry(scene->width()-60*(i+1)-20*i,40,scene->width()-20*(i+1)-60*i,80); //создал квадратные кнопки
            scene->addWidget(btn);
            i++;
        }
    }

    scene->addItem(base);
    score= new Score();
    scene->addItem(score);

    QTimer *timer = new QTimer;
    connect(timer, SIGNAL(timer), base, SLOT(spawn()));
    timer->start(2000);

    show();

}
