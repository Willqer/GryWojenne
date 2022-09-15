#ifndef ICON_SPAWN_H
#define ICON_SPAWN_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

/*! OBSŁUGA IKON TWORZĄCYCH JEDNOSTKI!*/
class Icon_Spawn: public QGraphicsPixmapItem{
    bool owner;     /*! flaga właściciela (gracza) ikony: 1 - zielony, 0 - czerwony!*/
    size_t type;    /*! flaga typu jednostki tworzonej przez ikonę: 1 - gwardzista, 2 - łucznik, 3 - rycerz!*/
public:
    /*! konstruktor  - ustawia wygląd ikon
     *  bool owner_def - domyślna wartość dla flagi właściciela
     *  size_t type_def! - domyślna wartość dla flagi typu jednostki*/
    Icon_Spawn(QGraphicsItem * parent=NULL,
                     bool owner_def=1,
                     size_t type_def=1);
    /*! tworzy i przekazuje kursorowi nowy obiekt do przestawienia!*/
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // ICON_SPAWN_H
