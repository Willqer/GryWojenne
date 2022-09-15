#ifndef UNIT_GUARD_H
#define UNIT_GUARD_H

#include "Unit.h"

//JEDNOSTKA GWARDZISTA
class Unit_Guard: public Unit{
public:
    //konstruktor - inicjalizuję jednostkę jako gwardzistę
    Unit_Guard(size_t speed_def=5,size_t hp_def=2,
               bool owner_def=1,size_t sight_def=150,
               size_t range_def=40);
    //atak gwardzisty (cios mieczem) - postawienie tokenu ataku na przeciwniku
    void attacking();
public slots:
    //pętla wyboru celu do ataku -  korzysta z metody nadrzędnej klasy unit
    void targeting();
};

#endif // UNIT_GUARD_H
