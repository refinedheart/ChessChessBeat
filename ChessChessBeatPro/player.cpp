#include "player.h"

#include <QLabel>
#include <QDebug>


Player::Player(QString pic)
{
    pix.load(pic);
    pix = pix.scaled(siz, siz, Qt::IgnoreAspectRatio, Qt::FastTransformation);
    pos = QPoint(StartXpos, StartYpos);
    item = new QLabel();
    item->setScaledContents(true);
    // item->adjustSize();
    QPoint getpos = QPoint(pos.x() - siz / 2, pos.y() - siz / 2);
    // getpos = QPoint(0, -200);
    item -> move(getpos);
    // qDebug() << getpos.x() << ' ' << getpos.y() << '\n';
    item -> setPixmap(pix);
    // item -> adjustSize();
    item -> show();
    moveD = 0;

}

Player :: ~Player() {
    // delete item;
}


void Player :: UpdatePos() {
    QPoint getpos = QPoint(pos.x() - siz / 2, pos.y() - siz/2);
    item -> move(getpos);
}

void Player :: moveUp() {
    pos = GetNextPos(pos, UP);
    UpdatePos();
}
void Player :: moveLeft() {
    pos = GetNextPos(pos, LEFT);
    UpdatePos();
}
void Player :: moveDown() {
    pos = GetNextPos(pos, DOWN);
    UpdatePos();
}
void Player :: moveRight() {
    pos = GetNextPos(pos, RIGHT);
    UpdatePos();
}
