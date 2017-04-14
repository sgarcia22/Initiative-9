#include "skeletonproject.h"
#include "player.h"


#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>


///Shooter Game

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Creating a Scene

    QGraphicsScene* scene = new QGraphicsScene();

    //Temp Player
    QGraphicsRectItem* player = new Player;
    //Set Points for rectangle (x,y, w, h)
    player->setRect(0,0, 100, 100);

    //Adding Item to the Screen
    scene->addItem(player);

    //Focus Item to get player input
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //Adding the GUI for the view, By Default it is invisible
    QGraphicsView* screen = new QGraphicsView(scene);

    //Disable Scroll Bar; Player Bullets and Player will not move screen
    screen->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    screen->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    screen->show();

    //Setting Resolution
    //Inside View
    screen->setFixedSize(1920,1080);
    //Outside Scene/View
    scene->setSceneRect(0,0,1920,1080);

    //Move Player Item from starting at Origin
    player->setPos(screen->width()/2, screen->height() - player->rect().height());


    //Spawn Randomly Positioned Enemies ///TODO CHANGE TO ANOTHER CLASS/REMOVE PERSON
    QTimer* timer = new QTimer();

    //TODO FIX, NOT READING SPAWN SLOT
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    //Spawns enemies every 2000 millisenconds, or 2 seconds
    timer->start(2000);


    return a.exec();
}
