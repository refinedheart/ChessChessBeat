#include "player.h"

#include <QLabel>
#include <QDebug>
#include <chrono>

// #include <QDataTime>


Player::Player(QString pic, int fg)
{
    Stopcnt = 0;
    scores = 0;
    graph = pic;
    getItemCnt = 0;
    layTrapcnt = 0;
    successTrapcnt = 0;

    if(fg == 0) pos = QPoint(StartXpos, StartYpos);
    else {
        pos = GetCoordPos(19, 19);
        // qDebug() << "Initial X = " << pos.x() << " Y = " << pos.y();
    }
    vec = new TrapItem*[limitTraps];
    for(int i = 0; i < limitTraps; ++i) vec[i] = new TrapItem(0, 0, 0, 0);
    id = new int*[limitTraps];
    for(int i = 0; i < limitTraps; ++i) id[i] = new int;
    // auto t = std :: chrono :: system_clock :: now();
    // auto tt = std :: chrono :: duration_cast<std :: chrono :: milliseconds> (t.time_since_epoch()).count();
    // qDebug() << tt;
    // vec.resize(3);
    // id.resize(3);
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


bool Player :: checkStop() {
    // return false;
    if(Stopcnt > 0) {
        // qDebug() << "S = " << Stopcnt;
        --Stopcnt;
        return true;
    }
    return false;
}

void Player :: UpdatePos() {
    // item -> close();
    // QPoint getpos = QPoint(pos.x() - siz / 2, pos.y() - siz/2);
    // item -> move(getpos);
    // item -> show();
}

void Player :: moveUp() {
    if(checkStop()) return ;
    QPoint npos = GetNextPos(pos, UP);
    if(checkOutOfWidget(npos)) return ;
    kp.push_back((moveMent){0, getTime()});
    pos = npos;
    UpdatePos();
}
void Player :: moveLeft() {
    if(checkStop()) return ;
    QPoint npos = GetNextPos(pos, LEFT);
    if(checkOutOfWidget(npos)) return ;
    kp.push_back((moveMent){1, getTime()});
    pos = npos;
    UpdatePos();
    // qDebug() << "Left!";
}
void Player :: moveDown() {
    if(checkStop()) return ;
    // qDebug() << "down??";
    // qDebug() << pos.x() << " " << pos.y();
    QPoint npos = GetNextPos(pos, DOWN);
    // qDebug() << StartXpos << ' ' << StartYpos << ' ' << npos.x() << " " << npos.y();
    // qDebug() << checkOutOfWidget(npos) << '\n';
    if(checkOutOfWidget(npos)) return ;
    kp.push_back((moveMent){2, getTime()});
    pos = npos;
    UpdatePos();
    // qDebug() << "Down!";
}
void Player :: moveRight() {
    if(checkStop()) return ;
    QPoint npos = GetNextPos(pos, RIGHT);
    if(checkOutOfWidget(npos)) return ;
    kp.push_back((moveMent){3, getTime()});
    pos = npos;
    UpdatePos();
}
bool Player :: checkOutOfWidget(QPoint npos) {
    // return false;
    if(npos.x() < StartXpos || npos.y() < StartYpos) return true;
    if(npos.x() > StartXpos + 18 * gapx || npos.y() > StartYpos + 18 * gapy) return true;
    return false;
}

