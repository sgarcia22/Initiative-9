#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>

Bullet::Bullet()
{
    //Setting the Rectangle for the Bullet
    setRect(0,0, 10, 50);

    //Connect signal to slot so that Bullet can move
    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);

}

void Bullet::move()
{
    //Moving the Bullet Upwards
    setPos(x(), y() - 20);

    //Check if Bullet is off the screen, if so Delete it
    if (pos().y() + rect().height() < 0) {
        //Remove from scene before deleting
        scene()->removeItem(this);
        delete this;
    }
}
