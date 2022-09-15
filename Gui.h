#ifndef GUI_H
#define GUI_H

#include "Counter.h"

//OBSŁUGA WYGLĄDU INFORMACJI I ELEMENTÓW OBSŁUGUJĄCYCH GRĘ
class Gui{
    //Obiekty trzymające dla danego gracza punktację
    Counter * Counter_green;
    Counter * Counter_red;
public:
    //Konstruktor - pozwala ustawić elementy gui (ikonki, napisy) na mapie
    Gui();
    //rysowanie planszy o danych parametrach
    void drawPanel(int x, int y, int width, int height, QColor color, double opacity);
    //mini metody zwracają wartości danego obiektu zliczającego
    Counter * Check_counter_green();
    Counter * Check_counter_red();
};

#endif // GUI_H
