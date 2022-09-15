#ifndef UNIT_GUARD_H
#define UNIT_GUARD_H

#include "Unit.h"

/*! JEDNOSTKA GWARDZISTA!*/
class Unit_Guard: public Unit{
public:
    /*! konstruktor - inicjalizaja jednostki (gwardzisty) i uruchomienie pętli sprawdzającej warunki!
        wartości początkowe
        size_t speed_def -> speed
        size_t hp_def    -> gp
        bool owner_def   -> owner
        size_t sight_def -> sight
        size_t range_def -> range
    !*/
    Unit_Guard(size_t speed_def=5,size_t hp_def=2,
               bool owner_def=1,size_t sight_def=150,
               size_t range_def=40);
    /*! atak gwardzisty - postawia obiekt Weapon_Sword w lokalizacji przeciwnika!*/
    void attacking() override;
public slots:
    /*! pętla wyboru celu do ataku -  korzysta z metody nadrzędnej klasy unit!*/
    void targeting();
};

#endif // UNIT_GUARD_H
