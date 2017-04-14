#include "player.h"
#include "bullet.h"
#include "enemy.h"
#include <QKeyEvent>
#include <QGraphicsScene>

void Player::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Left) {
        if (pos().x() > 0)
            setPos(x() - 10, y());
    }
    else if (event->key() == Qt::Key_Right) {
        //Position plus width of player minus width of scene
        if (pos().x() + 100 < 1920)
             setPos(x() + 10, y());
    }
    else if (event->key() == Qt::Key_Down) {
        if (pos().y() + 100 < 1080)
             setPos(x(), y() + 10);
    }
    else if (event->key() == Qt::Key_Up) {
        if (pos().y() > 0)
            setPos(x(), y() - 10);
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

void Player::spawn()
{
    //Spawning/Creating an Enemy

    Enemy* enemy = new Enemy();
    scene()->addItem(enemy);

}
