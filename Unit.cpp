#include "Unit.h"

#include "Unit_Archer.h"
#include "Unit_Guard.h"
#include "Unit_Knight.h"
#include "Weapon_Sword.h"
#include "Weapon_Arrow.h"
#include "Game.h"

#include <QPixmap>
#include <QPointF>
#include <QLineF>
#include <QTimer>
#include <qmath.h>

extern Game * game;


//KONSTRUKTOR
Unit::Unit(size_t speed_def, size_t hp_def,
           bool owner_def, size_t sight_def,
           size_t range_def,
           QString green_unit,QString red_unit,
           QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent)
{
    speed=speed_def;
    hp=hp_def;
    owner=owner_def;
    sight=sight_def;
    range=range_def;
    target_pos = QPointF(1000,800);

    //wyglad jednostki
    if(owner == 1){
        setPixmap(QPixmap(green_unit).scaled(35,35));
    }
    else{
        setPixmap(QPixmap(red_unit).scaled(35,35));
    }

    range_of_attack = field_creator(range,1);
    sight_of_enemy = field_creator(sight,1);


    //WALKING - lista punktow
    path_points << this->pos() << QPointF(0,0);
    path_indx = 0;
    path_target = path_points[0];
    rotating(path_target);

    //odswiezanie dla ruchu
    QTimer * walk_timer = new QTimer(this);
    connect(walk_timer,SIGNAL(timeout()),this,SLOT(marching()));
    walk_timer->start(200);
}
//WALKA
void Unit::attacking()
{
}
void Unit::targeting()
{
    if(game->check_phase_flag() == 1){
        //obiekty w zasiegu
        QList<QGraphicsItem *> items_in_range = range_of_attack->collidingItems();

        target_aquired = false;
        //jesli cos ponad sam obiekt znajduje sie w zasiegu
        double target_distance = 500;
        QPointF closest_enemy = QPointF(0,0);
        for (size_t i = 0, n = items_in_range.size(); i < n; ++i){
            Unit * enemy_unit = dynamic_cast<Unit *>(items_in_range[i]);
            if (enemy_unit){
                if(enemy_unit->owner != this->owner){
                    QLineF line(this->pos(),items_in_range[i]->pos());
                    double this_dist = line.length();
                    if (this_dist < target_distance){
                        target_distance = this_dist;
                        closest_enemy = items_in_range[i]->pos();
                        target_aquired = true;
                    }
                }
            }
        }

        if(target_aquired){
            target_pos = closest_enemy;
            attacking();
        }
    }
}
//CHODZENIE
void Unit::rotating(QPointF p){
    if(speed != 0){
        QLineF ln(pos(),p);
        setRotation(-1 * ln.angle());
    }
}
void Unit::marching(){
    if(game->check_phase_flag() == 1){
        //obrot w kierunku kolejnego punktu gdy w okolicy poprzedniego
        QLineF ln(pos(),path_target);
        if (ln.length() < 5){
             path_indx++;
            if ( path_indx >= path_points.size()){
                 return;
            }
            path_target = path_points[path_indx];
            rotating(path_target);
        }
        // obrot w kierunku celu
        double theta = rotation();
        double dy = speed * qSin(qDegreesToRadians(theta));
        double dx = speed * qCos(qDegreesToRadians(theta));
        setPos(x()+dx, y()+dy);
        //kolizja z jednostką
        QList<QGraphicsItem *> colliding_items = collidingItems();
        for (int i = 0, n = colliding_items.size(); i < n; ++i){
            if(typeid(*(colliding_items[i])) == typeid(Unit_Archer) ||
               typeid(*(colliding_items[i])) == typeid(Unit_Guard) ||
               typeid(*(colliding_items[i])) == typeid(Unit_Knight)){
                qDebug() << "KOLIZJA";
            }
        }



        //wykryj atak
        weapon_detection();
    }
}

QGraphicsPolygonItem * Unit::field_creator(size_t scale,size_t l_thickness)
{
    QGraphicsPolygonItem * field;
    //wzorcowy obszar wokol jednostki
    QVector<QPointF> Area_polygon_points;
    Area_polygon_points << QPoint(1,0) << QPoint(2,0) <<
                           QPoint(3,1) << QPoint(3,2) <<
                           QPoint(2,3) << QPoint(1,3) <<
                           QPoint(0,2) << QPoint(0,1);
    for(size_t i=0,n=Area_polygon_points.size();i<n;i++){
        Area_polygon_points[i] *= scale;
    }
    field = new QGraphicsPolygonItem(QPolygonF(Area_polygon_points),this);
    field->setPen(QPen(Qt::black, l_thickness));
    QPointF poly_center(1.5,1.5);
    poly_center *= scale;
    poly_center = mapToScene(poly_center);
    QPointF unit_center(x()+this->boundingRect().width()/2,y()+this->boundingRect().height()/2);
    QLineF ln(poly_center,unit_center);
    field->setPos(x()+ln.dx(),y()+ln.dy());
    return field;
}

void Unit::weapon_detection()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Weapon_Sword)){
            Weapon_Sword * enemy_weapon = dynamic_cast<Weapon_Sword *>(colliding_items[i]);
            if(enemy_weapon->check_owner_flag() != owner){
                hp -= 1;
                scene()->removeItem(colliding_items[i]);
                delete colliding_items[i];
                if(hp == 0){
                    if(this->owner == 1){
                        game->raise_red_dead();
                    }else{
                        game->raise_green_dead();
                    }
                    scene()->removeItem(this);
                    delete this;

                    if(game->check_green_dead() == 10 || game->check_red_dead() == 10){
                        game->gameOver();
                    }
                }
                return;
            }
        }else if (typeid(*(colliding_items[i])) == typeid(Weapon_Arrow)){
            Weapon_Arrow * enemy_weapon = dynamic_cast<Weapon_Arrow *>(colliding_items[i]);
            if(enemy_weapon->check_owner_flag() != owner){
                hp -= 1;
                scene()->removeItem(colliding_items[i]);
                delete colliding_items[i];
                if(hp == 0){
                    if(this->owner == 1){
                        game->raise_green_dead();
                    }else{
                        game->raise_red_dead();
                    }
                    scene()->removeItem(this);
                    delete this;
                    if(game->check_green_dead() == 10 || game->check_red_dead() == 10){
                        game->gameOver();
                    }
                }
                return;
            }
        }
    }
}
bool Unit::check_owner_flag(){
    return owner;
}


//if(game->check_phase_flag() == 1){
//    //obiekty w zasiegu
//    QList<QGraphicsItem *> items_in_range = sight_of_enemy->collidingItems();
//    path_target = center;
//    QLineF line1(this->pos(),center);
//    double target_distance = line1.length();
//    for (size_t i = 0, n = items_in_range.size(); i < n; ++i){
//        Unit * enemy_unit = dynamic_cast<Unit *>(items_in_range[i]);
//        if (enemy_unit){
//            if(enemy_unit->owner != this->owner){
//                //QLineF line(this->pos(),items_in_range[i]->pos());
//                QLineF line2(this->pos(),items_in_range[i]->pos());
//                double this_dist = line2.length();
//                if (this_dist < target_distance){
//                    target_distance = this_dist;
//                    path_target = items_in_range[i]->pos();

//                }
//            }
//        }
//    }

//    rotating(path_target);
//    double theta = rotation();
//    double dy = speed * qSin(qDegreesToRadians(theta));
//    double dx = speed * qCos(qDegreesToRadians(theta));
//    setPos(x()+dx, y()+dy);


//}
