#ifndef PLAYER_H
#define PLAYER_H


#include <QPixmap>
#include <QLabel>



// LeftTop = (466, 188)
// Delta d = 26
const int gap = 26;
const int StartXpos = 466;
const int StartYpos = 188 - 68 - gap; // (1, 1)
const int siz = 20;

const int UP = 0;
const int LEFT = 1;
const int DOWN = 2;
const int RIGHT = 3;

const int dx[] = {0, -1, 0, 1};
const int dy[] = {-1, 0, 1, 0};

inline QPoint GetNextPos(QPoint now, int dir) {
    int x = now.x(), y = now.y();
    x += dx[dir] * gap;
    y += dy[dir] * gap;
    return QPoint(x, y);
}

class Player
{
public:
    QLabel *item;
    QPoint pos;
    QPixmap pix;
    int moveD;
    Player(QString pic = "");
    ~Player();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void UpdatePos();
    bool checkOutOfWidget(QPoint npos);
};

#endif // PLAYER_H
