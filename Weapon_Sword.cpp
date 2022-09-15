#include "Weapon_Sword.h"

#include <QTimer>
#include <QPixmap>
#include <qmath.h>
#include <QGraphicsScene>

Weapon_Sword::Weapon_Sword(bool owner_def):Weapon(owner_def,0,
                                                         ":/graf/Grafiki/Green_Sword.png",
                                                         ":/graf/Grafiki/Red_Sword.png"){
}
void Weapon_Sword::attack(){
    scene()->removeItem(this);
    delete this;
}
