#include "Unit_Archer.h"

#include "Weapon_Arrow.h"
#include "Game.h"

#include <QTimer>

extern Game * game;

//Archer(speed,hp,owner,sight,range)
Unit_Archer::Unit_Archer(size_t speed_def, size_t hp_def,
                         bool owner_def, size_t sight_def,
                         size_t range_def):
                         Unit(speed_def,hp_def,owner_def,sight_def,range_def,
                              ":/graf/Grafiki/Green_Bow.png",
                              ":/graf/Grafiki/Red_Bow.png")
{
    //Cykliczne uruchamianie strzalu
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(targeting()));
    timer->start(1000);
}
void Unit_Archer::attacking()
{
    Weapon_Arrow * arrow = new Weapon_Arrow(owner,10);
    arrow->setPos(x()+boundingRect().width()/2,y()+boundingRect().height()/2);
    target_pos.setX(target_pos.x()+boundingRect().width()/2);
    target_pos.setY(target_pos.y()+boundingRect().height()/2);
    QLineF line(QPointF(x()+this->boundingRect().width()/2,y()+this->boundingRect().height()/2),target_pos);
    //QLineF line(unit_center,target_pos);
    int angle = -1*line.angle(); //przy size_t nie działa

    arrow->setRotation(angle);
    game->scene->addItem(arrow);
}
void Unit_Archer::targeting()
{
    Unit::targeting();
}
