#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>

Enemy::Enemy()
{

    //Set Random Position of Enemy
    int randomNumber = rand() % 1910;
    setPos(randomNumber, 0);


    //Setting the Rectangle for the Enemy
    setRect(0,0, 10, 50);

    //Connect signal to slot so that Enemy can move
    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);

}

void Enemy::move()
{
    //Moving the Enemy Downwards
    setPos(x(), y() + 15);

    //Check if Enemy is off the screen, if so Delete it
    if (pos().y() + rect().height() < 0) {
        //Remove from scene before deleting
        scene()->removeItem(this);
        delete this;
    }
}

