#include "Icon_Spawn.h"
#include "Game.h"
#include "Unit_Guard.h"
#include "Unit_Archer.h"
#include "Unit_Knight.h"

extern Game * game;

Icon_Spawn::Icon_Spawn(QGraphicsItem *parent,
                       bool owner_def,
                       size_t type_def): QGraphicsPixmapItem(parent)
{
    owner=owner_def;
    type=type_def;
    if(type == 2){
        if(owner == 1){
            setPixmap(QPixmap(":/graf/Grafiki/Build_Bow_Green.png").scaled(50,50));
        }else{
            setPixmap(QPixmap(":/graf/Grafiki/Build_Bow_Red.png").scaled(50,50));
        }
    }else if(type == 3){
        if(owner == 1){
            setPixmap(QPixmap(":/graf/Grafiki/Build_Horse_Green.png").scaled(50,50));
        }else{
            setPixmap(QPixmap(":/graf/Grafiki/Build_Horse_Red.png").scaled(50,50));
        }
    }else{
        if(owner == 1){
            setPixmap(QPixmap(":/graf/Grafiki/Build_Shield_Green.png").scaled(50,50));
        }else{
            setPixmap(QPixmap(":/graf/Grafiki/Build_Shield_Red.png").scaled(50,50));
        }
    }
}

void Icon_Spawn::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(game->check_phase_flag() == 0){
        if (!game->build &&
             game->check_owner_flag() == owner &&
             game->check_phase_flag() == 0)
        {
            if(type == 2)
            {
                //speed,hp,owner,sight,range
                game->build = new Unit_Archer(5,1,owner,150,100);
                if(owner == 1){
                    game->setCursor(QString(":/graf/Grafiki/Green_Bow.png"));
                }else {
                    game->setCursor(QString(":/graf/Grafiki/Red_Bow.png"));
                }
            }else if(type == 3)
            {
            //speed,hp,owner,sight,range
                game->build = new Unit_Knight(10,1,owner,150,40);
                if(owner == 1){
                    game->setCursor(QString(":/graf/Grafiki/Green_Horse.png"));
                }else{
                    game->setCursor(QString(":/graf/Grafiki/Red_Horse.png"));
                }
            }else
            {
            //speed,hp,owner,sight,range
                game->build = new Unit_Guard(5,2,owner,150,40);
                if(owner == 1){
                    game->setCursor(QString(":/graf/Grafiki/Green_Shield.png"));
                }else{
                    game->setCursor(QString(":/graf/Grafiki/Red_Shield.png"));
                }
            }
        }
    }
}
