#ifndef UNIT_KNIGHT_H
#define UNIT_KNIGHT_H

#include "Unit.h"

/*! JEDNOSTKA RYCERZ!*/
class Unit_Knight: public Unit{
public:
    /*! konstruktor - inicjalizaja jednostki (rycerza) i uruchomienie pętli sprawdzającej warunki!
        wartości początkowe
        size_t speed_def -> speed
        size_t hp_def    -> gp
        bool owner_def   -> owner
        size_t sight_def -> sight
        size_t range_def -> range
    !*/
    Unit_Knight(size_t speed_def=10,size_t hp_def=1,
                bool owner_def=1,size_t sight_def=150,
                size_t range_def=40);
    /*! atak rycerza - postawia obiekt Weapon_Sword w lokalizacji przeciwnika!*/
    void attacking() override;
public slots:
    /*! pętla wyboru celu do ataku -  korzysta z metody nadrzędnej klasy unit!*/
    void targeting();
};

#endif // UNIT_KNIGHT_H
