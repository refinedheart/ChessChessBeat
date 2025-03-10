#ifndef PLAYER_H
#define PLAYER_H


#include <QPixmap>
#include <QLabel>



// LeftTop = (466, 188)
// Delta d = 26
const int gap = 26;
const int StartXpos = 466;
const int StartYpos = 188;
const int siz = 20;

class Player
{
public:
    QLabel *item;
    QPoint pos;
    QPixmap pix;
    Player(QString pic = "");
    ~Player();
};

#endif // PLAYER_H
