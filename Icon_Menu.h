#ifndef ICON_MENU_H
#define ICON_MENU_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

//TWORZENIE IKON DOSTĘPNYCH W KAŻDYM MENU
class Icon_Menu:public QObject, public QGraphicsRectItem{
    Q_OBJECT

    //text wyświetlany na ikonie
    QGraphicsTextItem* text;
public:
    //Konstruktor rysuje ikonę z napisem
    Icon_Menu(QString name, QGraphicsItem* parent=NULL);

    //pozwala na interakcję z przyciskiem
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
signals:
    //sygnal wyzwalany przy nacisnieciu przycisku
    void clicked();
};

#endif // ICON_MENU_H
