#ifndef COUNTER_H
#define COUNTER_H

#include <QGraphicsTextItem>

/*! TWORZY OBIEKT PRZECHOWUJĄCY I OBSŁUGUJĄCY PUNKTY GRACZA DO WYDANIA (MONETY NA JEDNOSTKI)!*/
class Counter: public QGraphicsTextItem{
private:
    size_t score;       /*! punkty do wydania na jednostki!*/
    bool owner;         /*! flaga właściciela (gracza) i licznika: 1 - zielony, 0 - czerwony!*/
public:
    /*! KONSTRUKTOR - ustala wartości pól i wygląd licznika
    inicjalizuje parametry klasy owner_def->owner i score_init->score!*/
    Counter(bool owner_def=1,size_t score_init=10,QGraphicsItem * parent=NULL);
    /*! -1 do punktacji (score)!*/
    void lower();
    /*! +1 do punktacji (score)!*/
    void raise();
    /*! zwraca wartość punktacji (score)!*/
    size_t check_score();
};

#endif // COUNTER_H
