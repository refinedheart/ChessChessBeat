#include "player.h"

#include <QPainter>

Player::Player(QString pic) {
    pos = QPoint(StartXpos, StartYpos);
    pix.load(pic);

}


void Player :: draw(QPainter &painter) {
    painter.drawPixmap(pos.x() - sz, pos.y() - sz, sz << 1, sz << 1, pix);

}
