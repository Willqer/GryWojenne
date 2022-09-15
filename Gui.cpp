#include "Gui.h"

#include "Game.h"
#include "Counter.h"
#include "Icon_Spawn.h"
#include "Icon_Menu.h"
extern Game * game;

Gui::Gui()
{
    Icon_Spawn * g_icon_g = new Icon_Spawn(0,1,1); //GUARD ICON
    Icon_Spawn * g_icon_k = new Icon_Spawn(0,1,2); //KNIGHT ICON
    Icon_Spawn * g_icon_a = new Icon_Spawn(0,1,3); //ARCHER ICON
    Counter_green = new Counter(1,10);            //licznik zasoby gracza 1
    Counter_red = new Counter(0,10);              //licznik zasoby gracza 1
    Icon_Spawn * r_icon_g = new Icon_Spawn(0,0,1); //GUARD ICON
    Icon_Spawn * r_icon_k = new Icon_Spawn(0,0,2); //KNIGHT ICON
    Icon_Spawn * r_icon_a = new Icon_Spawn(0,0,3); //ARCHER ICON


    g_icon_g->setPos(5,5);
    g_icon_k->setPos(60,5);
    g_icon_a->setPos(115,5);
    Counter_green->setPos(170,5);

    Counter_red->setPos(game->scene->width()-305,5);
    r_icon_g->setPos(game->scene->width()-(3*55),5);
    r_icon_k->setPos(game->scene->width()-(2*55),5);
    r_icon_a->setPos(game->scene->width()-(1*55),5);


    game->scene->addItem(g_icon_g);
    game->scene->addItem(g_icon_k);
    game->scene->addItem(g_icon_a);
    game->scene->addItem(Counter_green);
    game->scene->addItem(Counter_red);
    game->scene->addItem(r_icon_g);
    game->scene->addItem(r_icon_k);
    game->scene->addItem(r_icon_a);
}

void Gui::drawPanel(int x, int y, int width, int height, QColor color, double opacity){
    // draws a panel at the specified location with the specified properties
    QGraphicsRectItem* panel = new QGraphicsRectItem(x,y,width,height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    panel->setBrush(brush);
    panel->setOpacity(opacity);
    game->scene->addItem(panel);
}

Counter *Gui::Check_counter_green()
{
    return Counter_green;
}
Counter *Gui::Check_counter_red()
{
    return Counter_red;
}
