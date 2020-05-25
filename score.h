#ifndef SCORE_H
#define SCORE_H

#include "head_libs.h"

class Score: public QGraphicsTextItem
{
public:
    Score(QGraphicsItem*parent=0);
    void increase();
    void goldIncrease(int a);
    int getScore();
    int getGold();
private:
    int gold_sum;
    int score;
};

#endif // SCORE_H
