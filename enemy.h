#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsRectItem>

class Enemy: public QObject, public QGraphicsRectItem
{
    //Adding Macro for QObject
    Q_OBJECT

    public:

        Enemy();

    public slots:

        void move();
};


#endif // ENEMY_H
