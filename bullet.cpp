#include "bullet.h"
#include <QTimer>

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
    setPos(x(), y() - 10);
}
