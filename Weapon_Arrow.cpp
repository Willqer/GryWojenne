#include "Weapon_Arrow.h"

#include <QPixmap>
#include <qmath.h>
#include <QGraphicsScene>

Weapon_Arrow::Weapon_Arrow(bool owner_def,
                           size_t speed_def):Weapon(owner_def,speed_def,
                                                    ":/graf/Grafiki/Green_Arrow.png",
                                                    ":/graf/Grafiki/Red_Arrow.png"){
}
void Weapon_Arrow::attack(){
    float theta = rotation();
    float dy = speed * qSin(qDegreesToRadians(theta));
    float dx = speed * qCos(qDegreesToRadians(theta));
    setPos(x()+dx, y()+dy);

    if (pos().y() < -50 || pos().y() > scene()->height()+50||
        pos().x() < -50 || pos().x() > scene()->width()+50){
        scene()->removeItem(this);
        delete this;
    }
}
