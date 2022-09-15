#ifndef UNIT_ARCHER_H
#define UNIT_ARCHER_H

#include "Unit.h"

//JEDNOSTKA ŁUCZNIK
class Unit_Archer:public Unit{
    Q_OBJECT
public:
    //konstruktor - inicjalizuję jednostkę jako łucznika
    Unit_Archer(size_t speed_def=5,size_t hp_def=1,
                bool owner_def=1,size_t sight_def=150,
                size_t range_def=100);
    //atak łucznika (strzał)
    void attacking();
public slots:
    //pętla wyboru celu do ataku -  korzysta z metody nadrzędnej klasy unit
    void targeting();
};

#endif // UNIT_ARCHER_H
