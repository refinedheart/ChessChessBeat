#ifndef PLAYER_H
#define PLAYER_H


#include <QPixmap>
#include <QLabel>



// LeftTop = (466, 188)
// Delta d = 26
const int gapx = 26;
const int gapy = 26;
const int StartXpos = 450 + gapx;
// const int StartYpos = 188 - 68 - gapy; // (1, 1)
const int StartYpos = 100 + gapy;
const int siz = 20;

const int UP = 0;
const int LEFT = 1;
const int DOWN = 2;
const int RIGHT = 3;

const int dx[] = {0, -1, 0, 1};
const int dy[] = {-1, 0, 1, 0};

inline QPoint GetNextPos(QPoint now, int dir) {
    int x = now.x(), y = now.y();
    // qDebug() << "dir = " << dir << " x = " << x << "dx = " << dx[dir];
    x += dx[dir] * gapx;
    y += dy[dir] * gapy;
    return QPoint(x, y);
}
inline QPoint GetCoordPos(int x, int y) {
    // (1, 1) = (StartX, StartY)
    return QPoint(StartXpos + (x - 1) * gapx, StartYpos + (y - 1) * gapy);
}

inline int regetposx(int x) {
    return (x - StartXpos) / gapx + 1;
}
inline int regetposy(int y) {
    return (y - StartYpos) / gapy + 1;
}

class Player
{
public:
    // QLabel *item;
    QPoint pos;
    QString graph;
    int scores;
    int Stopcnt;
    // int scores;
    Player(QString pic = "", int fg = 0);
    ~Player();
    bool checkStop();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void UpdatePos();
    bool checkOutOfWidget(QPoint npos);
};

#endif // PLAYER_H
