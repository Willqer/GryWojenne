#ifndef UNIT_ARCHER_H
#define UNIT_ARCHER_H

#include "Unit.h"

/*! JEDNOSTKA ŁUCZNIK!*/
class Unit_Archer:public Unit{
    Q_OBJECT
public:
    /*! konstruktor - inicjalizaja jednostki (łucznika) i uruchomienie pętli sprawdzającej warunki!
        wartości początkowe
        size_t speed_def -> speed
        size_t hp_def    -> gp
        bool owner_def   -> owner
        size_t sight_def -> sight
        size_t range_def -> range
    !*/
    Unit_Archer(size_t speed_def=5,size_t hp_def=1,
                bool owner_def=1,size_t sight_def=150,
                size_t range_def=100);
    /*! atak łucznika (strzał)!*/
    void attacking() override;
public slots:
    /*! pętla wyboru celu do ataku -  korzysta z metody nadrzędnej klasy unit!*/
    void targeting();
};

#endif // UNIT_ARCHER_H
