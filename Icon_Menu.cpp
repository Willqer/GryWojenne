#include "Icon_Menu.h"

#include <QGraphicsTextItem>
#include <QBrush>

Icon_Menu::Icon_Menu(QString name, QGraphicsItem *parent): QGraphicsRectItem(parent){
    // draw the rect
    setRect(0,0,200,50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);

    // draw the text
    text = new QGraphicsTextItem(name,this);
    int x = rect().width()/2 - text->boundingRect().width()/2;
    int y = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(x,y);
}

void Icon_Menu::mousePressEvent(QGraphicsSceneMouseEvent *event){
    emit clicked();
}
