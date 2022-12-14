#ifndef WEAPON_H
#define WEAPON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

/*! WZORZEC BRONI REPREZENTUJĄCYCH ATAKI JEDNOSTEK!*/
class Weapon: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
protected:
    size_t speed;   /*! prędkość ruchu jednostki!!*/
    bool owner;     /*! właściciel broni(gracz)!*/

    /*! Koonstruktor - inicjalizaja broni i uruchomienie pętli sprawdzającej warunki!
        wartości początkowe
        bool owner_def   -> owner
        ize_t speed_def -> speed
        size_t sight_def -> sight
        size_t range_def -> range!*/
    Weapon(bool owner_def=1,size_t speed_def=0,
          QString green_unit=":/graf/Grafiki/Green_Arrow.png",
          QString red_unit=":/graf/Grafiki/Red_Arrow.png",
          QGraphicsItem * parent=NULL);
public:
    /*! podaje właściciela broni!*/
    bool check_owner_flag();
public slots:
    /*! wirtualny metoda reprezentuje mozliwosc ataku klas dziedziczących!*/
    virtual void attack();
};

#endif // WEAPON_H
