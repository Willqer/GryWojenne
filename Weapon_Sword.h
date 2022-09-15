#ifndef WEAPON_SWORD_H
#define WEAPON_SWORD_H

#include "Weapon.h"

//BROŃ - MIECZ
class Weapon_Sword: public Weapon{
public:
    //inicjalizacja broni jako miecza
    Weapon_Sword(bool owner_def=1);
public slots:
    //sposób ataku miecza - postawienie go na pozaycji wroga
    void attack();
};

#endif // WEAPON_SWORD_H
