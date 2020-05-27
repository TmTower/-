#ifndef BTN_H
#define BTN_H

#include "head_libs.h"

class Btn:public QPushButton
{
    Q_OBJECT
public:
    Btn(QGraphicsItem*parent=0);
    string name;
    int cost;
    void get(int c, string n);
    void chek();
    void arUp();
    void min1Un();
    void min2Un();
    void min1Up();
    void min2Up();

};

#endif // BTN_H
