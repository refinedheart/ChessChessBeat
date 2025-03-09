#include "gameroom.h"
#include <QPaintEvent>
#include <QPainter>
GameRoom::GameRoom(QWidget *parent)
    : QWidget{parent}
{}

void GameRoom :: paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    QPixmap pix(":/Chess-19.jpeg");
    painter.drawPixmap(0, 0, this -> width(), this -> height(), pix);
}
