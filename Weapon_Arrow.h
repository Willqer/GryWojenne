#ifndef WEAPON_ARROW_H
#define WEAPON_ARROW_H

#include "Weapon.h"

//BROŃ - STRZAŁA
class Weapon_Arrow: public Weapon{
public:
    //inicjalizacja broni jako strzały
    Weapon_Arrow(bool owner_def=1,size_t speed_def=10);
public slots:
    //sposób ataku stzały - lot
    void attack();
};



#endif // WEAPON_ARROW_H
