#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>

Bullet::Bullet(/*QGraphicsItem* parent*/): QObject(), QGraphicsPixmapItem(/*parent*/)
{
    //Setting the Rectangle for the Bullet
    setPixmap(QPixmap(":/images/Images/Bullet.png"));

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
    if (pos().y() /*+ this.height()*/ < 0) {   //FIX THE HEIGHT THING
        //Remove from scene before deleting
        scene()->removeItem(this);
        delete this;
    }
}
