#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QPointF>

#include "Unit.h"
#include "Counter.h"
#include "Gui.h"

//KLASA OBSŁUGUJĄCA CAŁĄ LOGIKĘ GRY
class Game: public QGraphicsView{
    Q_OBJECT

    QPointF map_center;

    bool side;                      //flaga aktualnego gracza (tury): 1 - zielony, 0 - czerwony
    bool phase;                     //flaga etapu gry (0 turowe ustawianie elementow ->  1 rozegranie bitwy)
    size_t dead_counter_green;      //ilosc zniszczonych zielonych jednostek
    size_t dead_counter_red;        //ilosc zniszczonych czerwonych jednostek
    QGraphicsPixmapItem * cursor;   //grafika wyglądu kursora
    Gui * gui;                      //GUI - wyświetlane ikony i napisy
public:
    Unit * build;                   //kontener na budowaną jednostkę trzymaną przez kursor
    QGraphicsScene * scene;         //scena gry

    //Konstruktor - tworzy i modyfikuje nową scenę
    Game(QWidget * parent=0);
    //pierwszy etap - wyswietla okno menu
    void mainMenu();
    //wyswietla wynik rozrgrywki i pozwala na ponowienie gr
    void gameOver();

    //ustawia wygląd kursora
    void setCursor(QString filename);
    //podążanie wyglądu kursora za kursorerm
    void mouseMoveEvent(QMouseEvent *event);
    //pozwala ustawic na planszy obiekt trzymany przez kursor
    void mousePressEvent(QMouseEvent *event);

    //mini metody pozwalające sprawdzac wartosci odpowiednich pól
    bool check_owner_flag();
    bool check_phase_flag();
    size_t check_green_dead();
    size_t check_red_dead();
    //mini metody pozwalające zwiększać o 1 wartości odpowiednich pól
    void raise_green_dead();
    void raise_red_dead();

    QPointF check_map_center();

public slots:
    //Pozwala uruchomić główną rozgrywkę ustawiając przy okazji odpowiednie startowe wartości
    void start();
};



#endif // GAME_H
