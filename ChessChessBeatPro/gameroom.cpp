#include "gameroom.h"
#include <QPaintEvent>
#include <QPainter>
#include <QPushButton>

#include "player.h"


#include "tool.h"

#include <QLabel>

#include <QPainter>

GameRoom::GameRoom(QWidget *parent)
    : QWidget{parent}
{
    // 页面设置
    this -> setFixedSize(1400, 800);

    // make sure the first position
    // Tool *now = new Tool;
    // now -> show();
    // Tool::
    // 创建一个 QLabel 用于显示鼠标坐标
    \
    // label -> move(1000, 1000);

    // 设置布局
    // QVBoxLayout *layout = new QVBoxLayout(this);
    // layout->addWidget(label);
    // setLayout(layout);

    // 创建一个 QLabel 用于显示鼠标坐标
    label = new QLabel(this);
    label->setGeometry(10, 10, 200, 20);

    // 启用鼠标跟踪功能
    setMouseTracking(true);



    ////////////




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
    backbtn -> move(1200, 700);
    backbtn -> setFixedSize(150, 50);





    // LeftTop = (466, 188)
    // Delta d = 26


    Player machine(":/M-up.png");
    machine.item -> setParent(this);



}

void GameRoom :: paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    QPixmap pix(":/RoomBackGround.jpg");
    painter.drawPixmap(0, 0, this -> width(), this -> height(), pix);
    pix.load(":/Chess-19.jpeg");
    painter.drawPixmap(450, 100, 500, 500, pix);
}
