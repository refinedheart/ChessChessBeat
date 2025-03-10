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
    // qDebug() << "Parent window position:" << item->parentWidget()->pos();
    // qDebug() << "Parent window size:" << item->parentWidget()->size();
}

Player :: ~Player() {
    // delete item;
}
