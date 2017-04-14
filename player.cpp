#include "player.h"
#include "bullet.h"
#include <QKeyEvent>
#include <QGraphicsScene>

void Player::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Left) {
        setPos(x() - 10, y());
    }
    else if (event->key() == Qt::Key_Right) {
        setPos(x() + 10, y());
    }
    else if (event->key() == Qt::Key_Down) {
        setPos(x(), y() + 10);
    }
    else if (event->key() == Qt::Key_Up) {
        setPos(x() + 10, y() - 10);
    }
    else if (event->key() == Qt::Key_Space) {

        //Creating a Bullet
        Bullet* bullet = new Bullet();
        //Set Position of Bullet
        bullet->setPos(x(), y());
        //Add Bullet to Scene
        scene()->addItem(bullet);

    }
}
