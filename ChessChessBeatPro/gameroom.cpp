#include "gameroom.h"
#include <QPaintEvent>
#include <QPainter>
#include <QPushButton>

GameRoom::GameRoom(QWidget *parent)
    : QWidget{parent}
{
    // backbtn
    QPushButton *backbtn = new QPushButton(this);
    backbtn -> setText("累了， 休息一下");
    QFont backFont("宋体", 16, QFont :: Bold);
    backbtn -> setFont(backFont);
    QPalette backP = backbtn -> palette();
    backP.setColor(QPalette :: ButtonText, Qt :: black);
    backbtn -> setPalette(backP);
    connect(backbtn, &QPushButton :: clicked, [=](){
        emit this -> back_to_select();
    });
    backbtn -> move(800, 700);
    backbtn -> setFixedSize(150, 50);

    // 页面设置
    this -> setFixedSize(1000, 800);

}

void GameRoom :: paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    QPixmap pix(":/RoomBackGround.jpg");
    painter.drawPixmap(0, 0, this -> width(), this -> height(), pix);
    pix.load(":/Chess-19.jpeg");
    painter.drawPixmap(200, 100, 600, 600, pix);
}
