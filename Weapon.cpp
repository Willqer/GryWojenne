#include "Weapon.h"

#include <QTimer>

Weapon::Weapon(bool owner_def, size_t speed_def, QString green_unit, QString red_unit, QGraphicsItem *parent)
{
    owner = owner_def;
    speed = speed_def;


    if(owner == 1){
        setPixmap(QPixmap(green_unit).scaled(35,35));
    }
    else{
        setPixmap(QPixmap(red_unit).scaled(35,35));
    }


    QTimer * fly_timer  = new QTimer(this);
    connect(fly_timer ,SIGNAL(timeout()),this,SLOT(attack()));
    fly_timer -> start(50);
}

bool Weapon::check_owner_flag(){
    return owner;
}

void Weapon::attack()
{
    //ATAK!
}
