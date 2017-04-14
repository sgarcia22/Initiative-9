#include "skeletonproject.h"
#include <QApplication>
#include <QGraphicsScene>
#include "player.h"
#include <QGraphicsView>

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

    return a.exec();
}
