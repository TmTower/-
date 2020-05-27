#include "score.h"

Score::Score(QGraphicsItem *parent):
    QGraphicsTextItem(parent)
{
    score=0;
    gold_sum=0;
    setPlainText(QString("Score: ")+QString::number(score));
    setDefaultTextColor(Qt::yellow);
    setFont(QFont("times",16));
}

void Score::increase()
{
    score++;
    setPlainText(QString("Score: ")+QString::number(score));
}

int Score::getScore()
{
    return score;
}

int Score::getGold()
{
    return gold_sum;
}

void Score::goldIncrease(int a)
{
    gold_sum+=a;
}
