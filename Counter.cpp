#include "Counter.h"

#include <QFont>

#include "Game.h"

extern Game * game;

Counter::Counter(bool owner_def,size_t score_init,QGraphicsItem *parent)
{
    score = score_init;
    owner = owner_def;
   if(owner){
       setPlainText(QString("P1 Money: ") + QString::number(score));
       setDefaultTextColor(Qt::darkGreen);
       setFont(QFont("arial",16));
   }else{
       setPlainText(QString("P2 Money: ") + QString::number(score));
       setDefaultTextColor(Qt::darkRed);
       setFont(QFont("arial",16));
   }
}

void Counter::lower()
{
    score -= 1;
    if(owner){
        setPlainText(QString("P1 Money: ") + QString::number(score));
    }else{
        setPlainText(QString("P2 Money: ") + QString::number(score));
    }
}
void Counter::raise()
{
    score += 1;
    if(owner){
        setPlainText(QString("P1 Money: ") + QString::number(score));
    }else{
        setPlainText(QString("P2 Money: ") + QString::number(score));
    }
}
size_t Counter::check_score()
{
    return score;
}
