#ifndef UNIT_H
#define UNIT_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QList>
#include <QPointF>
#include <QGraphicsItem>

//WZORZEC JEDNOSTKI
class Unit:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
protected:
    QPointF center;


    bool target_aquired;                    //flaga przyjęcia celu
    bool owner;                             //flaga  właściciela jednostki
    QPointF target_pos;                     //położenie istniejącego celu
    size_t speed;                           //prędkość ruchu jednostki
    size_t hp;                              //punkty wytrzymałości jednostki
    size_t sight;                           //zasięg widzenia jednostki
    size_t range;                           //zasięg ataku jednostki

    QGraphicsPolygonItem *sight_of_enemy;   //obszar widoku jednostki
    QGraphicsPolygonItem *range_of_attack;  //obszar ataku jednostki

    //chodzenie
    QList<QPointF> path_points;             //bufor punktóW do przejścia
    QPointF path_target;                    //aktualny cel
    int  path_indx;                         //index aktualnie sprawdzanego punktu

    //konstruktor - inicjalizaja jednostki i uruchomienie pętli sprawdzającej warunki
    Unit(size_t speed_def=1,size_t hp_def=1,
         bool owner_def=1,size_t sight_def=1,
         size_t range_def=1,
         QString green_unit=":/graf/Grafiki/Green_Shield.png",
         QString red_unit=":/graf/Grafiki/Red_Shield.png",
         QGraphicsItem *parent=0);

    //wirtualna funkcja odpowiadająca atakowi kolejnych jednostek
    virtual void attacking();
public slots:
    //pętla wyboru celu do ataku
    void targeting();
    //pętla ruchu i wykrywania warunków wokół jednostki
    void marching();
protected:
    //tworzenie pól widzenia i atakowania
    QGraphicsPolygonItem * field_creator(size_t scale,size_t l_thickness);
    //wykrycie kolizji z bronią wroga (przyjęcie ataku
    void weapon_detection();
    //obracanie się do opdowiedniego punktu
    void rotating(QPointF p);
public:
    //mini metoda informuje o właścicielu jednostki
    bool check_owner_flag();
};

#endif // UNIT_H
