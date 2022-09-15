#include "Game.h"

#include "Unit_Archer.h"
#include "Unit_Guard.h"
#include "Unit_Knight.h"
#include "Icon_Spawn.h"
#include "Gui.h"
#include "Icon_Menu.h"
//#include "Arrow.h"

#include <QGraphicsScene>


Game::Game(QWidget *parent): QGraphicsView()
{
    //nowa scena
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,1280,720);

    //wyglad sceny
    setFixedSize(1280,720);
    map_center.setX(1280/2);
    map_center.setY(720/2);
    //setBackgroundBrush(QBrush(QImage(":/graf/Grafiki/Simple_Map.png").scaled(1280,720)));
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //ustalenie aktywnej sceny
    setScene(scene);
    //ustawianie kursora (zmienia się przy akcji np budowania
    cursor = nullptr;
    build = nullptr;
    setMouseTracking(true);
}

void Game::start()
{
    side = 1;
    phase = 0;
    dead_counter_green = 0;
    dead_counter_red = 0;
    scene->clear();
    setBackgroundBrush(QBrush(QImage(":/graf/Grafiki/Simple_Map.png").scaled(1280,720)));
    gui = new Gui();
    //ustawianie kursora (zmienia się przy akcji np budowania
    cursor = nullptr;
    build = nullptr;
    setMouseTracking(true);
}
void Game::mainMenu(){
    // create the title text
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("GRY WOJENNE"));
    QFont titleFont("Arial",50);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    // create the play button
    Icon_Menu* play = new Icon_Menu(QString("Graj"));
    int px = this->width()/2 - play->boundingRect().width()/2;
    int py = 275;
    play->setPos(px,py);
    connect(play,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(play);

    // create the quit button
    Icon_Menu* quit = new Icon_Menu(QString("Wyjdz"));
    int qx = this->width()/2 - quit->boundingRect().width()/2;
    int qy = 350;
    quit->setPos(qx,qy);
    connect(quit,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quit);
}
void Game::gameOver()
{
    QString  text;
       if (dead_counter_green > dead_counter_red){
           text = "RED VICTORY";
       }
       else if (dead_counter_green < dead_counter_red){
           text = "GREEN VICTORY";
       }
       else {
           text = "TIE";
       }
        scene->clear();
        gui->drawPanel(0,0,1280,720,Qt::white,1);
        gui->drawPanel(440,184,400,400,Qt::lightGray,1);

        Icon_Menu* again = new Icon_Menu(QString("Od nowa"));
        again->setPos(540,300);
        scene->addItem(again);
        connect(again,SIGNAL(clicked()),this,SLOT(start()));

        Icon_Menu* quit = new Icon_Menu(QString("Quit"));
        quit->setPos(540,375);
        scene->addItem(quit);
        connect(quit,SIGNAL(clicked()),this,SLOT(close()));

        QGraphicsTextItem* overText = new QGraphicsTextItem(text);
        int x = rect().width()/2 - overText->boundingRect().width()/2;
        overText->setPos(x,225);
        scene->addItem(overText);
}


void Game::setCursor(QString filename)
{
   cursor = new QGraphicsPixmapItem();
   cursor->setPixmap(QPixmap(filename).scaled(35,35));
   scene->addItem(cursor);
}
void Game::mouseMoveEvent(QMouseEvent *event)
{
    if (cursor){
            cursor->setPos(event->pos());
        }
}
void Game::mousePressEvent(QMouseEvent *event){
    if(phase == 0){
        if (build &&
            cursor->pos().y() > 60){
            //kolizja
            QList<QGraphicsItem *> items = cursor->collidingItems();
            for (size_t i = 0, n = items.size(); i < n; i++){
                if (dynamic_cast<Unit*>(items[i])){
                    return;
                }
            }

            if((side == 1 && build->check_owner_flag() == 1 && cursor->pos().x() < scene->width()/2) ||
               (side == 0 && build->check_owner_flag() == 0 && cursor->pos().x() > scene->width()/2)){
                    scene->addItem(build);
                    build->setPos(event->pos());
                    scene->removeItem(cursor);
                    delete cursor;
                    cursor = nullptr;
                    build = nullptr;
                    if(this->side == 1){
                        gui->Check_counter_green()->lower();
                    }else{
                        gui->Check_counter_red()->lower();
                    }
                    if(gui->Check_counter_red()->check_score() == 0 &&
                       gui->Check_counter_green()->check_score() == 0){
                        phase = 1;
                    }
                    this->side = !this->side;
            }
        }else{
            QGraphicsView::mousePressEvent(event);
        }
    }
}

bool Game::check_owner_flag()
{
    return side;
}
bool Game::check_phase_flag()
{
    return phase;
}
size_t Game::check_green_dead()
{
    return dead_counter_green;
}
size_t Game::check_red_dead()
{
    return dead_counter_red;
}
void Game::raise_green_dead()
{
    dead_counter_green += 1;
}
void Game::raise_red_dead()
{
    dead_counter_red += 1;
}

QPointF Game::check_map_center()
{
    return map_center;
}
