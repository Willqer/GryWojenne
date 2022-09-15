#ifndef ICON_MENU_H
#define ICON_MENU_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

/*! TWORZENIE IKON DOSTĘPNYCH W KAŻDYM MENU!*/
class Icon_Menu:public QObject, public QGraphicsRectItem{
    Q_OBJECT

    /*! text wyświetlany na ikonie!*/
    QGraphicsTextItem* text;
public:
    /*! Konstruktor rysuje ikonę z napisem
     *  QString name -przekazuje bezopośrdnio tekst w formie ciągu znaków
     *  przekazywanym do graficznego obiektu tekstowego QGraphicsTextItem (text).!*/
    Icon_Menu(QString name, QGraphicsItem* parent=NULL);

    /*! metoda przy wciśnięciu przycisku emituje sygnał, który może być wykorzystany, jako wyzwalacz!*/
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
signals:
    /*! sygnal emitowany przy nacisnieciu przycisku1*/
    void clicked();
};

#endif // ICON_MENU_H
