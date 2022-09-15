#ifndef UNIT_H
#define UNIT_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QList>
#include <QPointF>
#include <QGraphicsItem>

//WZORZEC JEDNOSTKI!*/
class Unit:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
protected:
    QPointF center;


    bool target_aquired;                    /*! flaga przyjęcia celu!*/
    bool owner;                             /*! flaga  właściciela jednostki!*/
    QPointF target_pos;                     /*! położenie istniejącego celu!*/
    size_t speed;                           /*! prędkość ruchu jednostki!*/
    size_t hp;                              /*! punkty wytrzymałości jednostki!*/
    size_t sight;                           /*! zasięg widzenia jednostki!*/
    size_t range;                           /*! zasięg ataku jednostki!*/

    QGraphicsPolygonItem *sight_of_enemy;   /*! obszar widoku jednostki!*/
    QGraphicsPolygonItem *range_of_attack;  /*! obszar ataku jednostki!*/

    /*! chodzenie!*/
    QList<QPointF> path_points;             /*! bufor punktóW do przejścia!*/
    QPointF path_target;                    /*! aktualny cel!*/
    int  path_indx;                         /*! index aktualnie sprawdzanego punktu!*/

    /*! konstruktor - przekazanie domyślniych wartości do pól jednostki,
     *  uruchomienie zapętlenia sygnału. Sygnał uruchamia cyklicznie metodę walking(),
     *  która pozwala na przemieszczanie się obiektu i cykliczne wykrywanie kolizji
        wartości początkowe
        size_t speed_def -> speed
        size_t hp_def    -> gp
        bool owner_def   -> owner
        size_t sight_def -> sight
        size_t range_def -> range

        QString green_unit  przekazuje link z wyglądem zielonej jednostki
        QString red_unit    przekazuje link z wyglądaem czerwonej jednostki
    !*/
    Unit(size_t speed_def=1,size_t hp_def=1,
         bool owner_def=1,size_t sight_def=1,
         size_t range_def=1,
         QString green_unit=":/graf/Grafiki/Green_Shield.png",
         QString red_unit=":/graf/Grafiki/Red_Shield.png",
         QGraphicsItem *parent=0);

    /*! wirtualna metoda odpowiadająca za implementację sposobu ataku dla każdej jednostki!*/
    virtual void attacking();
public slots:
    /*! metoda odpowiada za wybór celu do ataku przez jednostkę
    ocenia pod  tym kątem wszystkie jednostki w zakresie*/
    void targeting();
    /*! zapętlenie wywoływana metoda, odpowiada za przemieszczanie obiektu się po scenie i wykrywanie kolizji!*/
    void marching();
protected:
    /*! metoda tworzy i zwraca przeskalowany poligon
     *  size_t scale, opowiada za przeskalowanie poligonu
     *  int l_thickness - grubość krawędzi przy wyświetlaniu poligonu!*/
    QGraphicsPolygonItem * field_creator(size_t scale,int l_thickness);
    /*! wykrycie kolizji z bronią wroga (przyjęcie ataku!*/
    void weapon_detection();
    /*! obracanie się do opdowiedniego punktu
     *  QPointF p - punkt docelowy. obrót wykonuje się tak, że obekt znajduje się przodem do punktu p!*/
    void rotating(QPointF p);
public:
    /*! metoda zwraca aktualnego właściciela (owner) obiektu!*/
    bool check_owner_flag();
};

#endif // UNIT_H
