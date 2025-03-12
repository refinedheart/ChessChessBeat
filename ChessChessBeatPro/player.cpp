#include "player.h"

#include <QLabel>
#include <QDebug>


Player::Player(QString pic, int fg)
{
    graph = pic;
    if(fg == 0) pos = QPoint(StartXpos, StartYpos);
    else {
        pos = GetCoordPos(19, 19);
        // qDebug() << "Initial X = " << pos.x() << " Y = " << pos.y();
    }
    // item = new QLabel();

    // item->setScaledContents(true);
    // item->adjustSize();
    // QPoint getpos = QPoint(pos.x() - siz / 2, pos.y() - siz / 2);
    // getpos = QPoint(0, -200);
    // item -> move(getpos);
    // qDebug() << getpos.x() << ' ' << getpos.y() << '\n';
    // item -> setPixmap(pix);
    // item -> adjustSize();
    // item -> show();


}

Player :: ~Player() {
    // delete item;
}


void Player :: UpdatePos() {
    // item -> close();
    // QPoint getpos = QPoint(pos.x() - siz / 2, pos.y() - siz/2);
    // item -> move(getpos);
    // item -> show();
}

void Player :: moveUp() {
    QPoint npos = GetNextPos(pos, UP);
    if(checkOutOfWidget(npos)) return ;
    pos = npos;
    UpdatePos();
}
void Player :: moveLeft() {
    QPoint npos = GetNextPos(pos, LEFT);
    if(checkOutOfWidget(npos)) return ;
    pos = npos;
    UpdatePos();
    // qDebug() << "Left!";
}
void Player :: moveDown() {
    // qDebug() << "down??";
    // qDebug() << pos.x() << " " << pos.y();
    QPoint npos = GetNextPos(pos, DOWN);
    // qDebug() << StartXpos << ' ' << StartYpos << ' ' << npos.x() << " " << npos.y();
    // qDebug() << checkOutOfWidget(npos) << '\n';
    if(checkOutOfWidget(npos)) return ;
    pos = npos;
    UpdatePos();
    // qDebug() << "Down!";
}
void Player :: moveRight() {
    QPoint npos = GetNextPos(pos, RIGHT);
    if(checkOutOfWidget(npos)) return ;
    pos = npos;
    UpdatePos();
}
bool Player :: checkOutOfWidget(QPoint npos) {
    // return false;
    if(npos.x() < StartXpos || npos.y() < StartYpos) return true;
    return false;
}
