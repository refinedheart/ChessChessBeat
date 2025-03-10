#ifndef PLAYER_H
#define PLAYER_H

#include <QPaintEvent>

#include <QPixmap>

#include <QPainter>

const int gap = 26;
const int StartXpos = 466;
const int StartYpos = 188;
const int sz = 10;


class Player
{
    // LeftTop = (466, 188)
    // Delta d = 26
public:
    int HeadDirect; // 0, 1, 2, 3 -> up, left, down, right , trans = xor 2
    QPoint pos;
    QPixmap pix;

public:
    Player(QString pic = "");
    void draw(QPainter &painter);
};

#endif // PLAYER_H
