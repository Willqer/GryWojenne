#ifndef GUI_H
#define GUI_H

#include "Counter.h"

/*! OBSŁUGA WYGLĄDU INFORMACJI I ELEMENTÓW OBSŁUGUJĄCYCH GRĘ!*/
class Gui{
    /*! Obiekty trzymające dla danego gracza punktację!*/
    Counter * Counter_green;    /*! punktacja gracza 1 (zielony)!*/
    Counter * Counter_red;      /*! punktacja gracza 0 (czerwony)!*/
public:
    /*! Konstruktor - pozwala ustawić elementy gui (ikonki, napisy) na mapie*/
    Gui();
    /*!
    konstruktor - rysowanie planszy o danych parametrach
    int x             współrzędna x planszy
    int y             współrzędna y planszy
    int width         szerokość planszy
    int height        wysokość planszy
    QColor color      kolor panelu
    double opacity    nieprzezroczystość panelu
    !*/
    void drawPanel(int x, int y, int width, int height, QColor color, double opacity);
    /*! metody zwracają wartości danego obiektu zliczającego!*/
    Counter * Check_counter_green();    /*! zwraca wartość!*/
    Counter * Check_counter_red();      /*!  S FASFS           !*/
};

#endif // GUI_H
