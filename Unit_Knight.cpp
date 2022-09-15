#include "Unit_Knight.h"

#include "Weapon_Sword.h"
#include "Game.h"

#include <QTimer>

extern Game * game;

//Knight(speed,hp,owner,sight,range)
Unit_Knight::Unit_Knight(size_t speed_def, size_t hp_def,
                         bool owner_def, size_t sight_def,
                         size_t range_def):
                         Unit(speed_def,hp_def,owner_def,sight_def,range_def,
                         ":/graf/Grafiki/Green_Horse.png",
                         ":/graf/Grafiki/Red_Horse.png")
{
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(targeting()));
    timer->start(1000);
}
void Unit_Knight::attacking()
{
    Weapon_Sword * sword = new Weapon_Sword(owner);
    sword->setPos(target_pos);

    game->scene->addItem(sword);
}
void Unit_Knight::targeting()
{
    Unit::targeting();
}
