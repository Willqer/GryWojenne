#ifndef UNIT_KNIGHT_H
#define UNIT_KNIGHT_H

#include "Unit.h"

//JEDNOSTKA RYCERZ
class Unit_Knight: public Unit{
public:
    //konstruktor - inicjalizuję jednostkę jako rycerza
    Unit_Knight(size_t speed_def=10,size_t hp_def=1,
                bool owner_def=1,size_t sight_def=150,
                size_t range_def=40);
    //atak rycerza (cios mieczem) - postawienie tokenu ataku na przeciwniku
    void attacking();
public slots:
    //pętla wyboru celu do ataku -  korzysta z metody nadrzędnej klasy unit
    void targeting();
};

#endif // UNIT_KNIGHT_H
