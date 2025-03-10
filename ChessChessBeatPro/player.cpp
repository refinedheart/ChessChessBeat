#include "player.h"

#include <QLabel>


Player::Player(QString pic)
{
    pix.load(pic);
    pix = pix.scaled(siz, siz, Qt::IgnoreAspectRatio, Qt::FastTransformation);
    pos = QPoint(StartXpos, StartYpos);
    item = new QLabel();
    item -> setFixedSize(20, 20);
    QPoint getpos = QPoint(pos.x() - siz / 2, pos.y() - siz / 2);
    item -> move(pos);
    item -> setPixmap(pix);
    // item -> adjustSize();
    item -> show();
}

Player :: ~Player() {
    // delete item;
}
