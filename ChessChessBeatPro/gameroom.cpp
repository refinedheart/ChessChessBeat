#include "gameroom.h"
#include <QPaintEvent>
#include <QPainter>
#include <QPushButton>
#include <QDebug>
#include "player.h"


// #include "tool.h"

#include <QLabel>

#include <QPainter>

const int gridSize = 30;

const int Mx = 400;
const int My = 100;


GameRoom::GameRoom(QWidget *parent)
    : QWidget{parent}
{
    // 页面设置
    this -> setFixedSize(1400, 800);


    // timer-update
    updateTimer.setInterval(16);
    connect(&updateTimer, &QTimer :: timeout, [=](){
        update();
    });
    updateTimer.start();
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

    //创建一个 QLabel 用于显示鼠标坐标
    // label = new QLabel(this);
    // label->setGeometry(10, 10, 200, 20);

    // // 启用鼠标跟踪功能
    // setMouseTracking(true);



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

    machine = Player(":/M-up.png");
    // machine.item -> setParent(this); // A player, up down
    // qDebug() << machine.pos.x() << " " << machine.pos.y();
    human = Player(":/K-up.png", 1);
    // human.item -> setParent(this); // B player, WASD
    // qDebug() << machine.pos.x() << " " << machine.pos.y();
    connect(this, &GameRoom :: upKeyPressed, [&](){
        machine.moveUp();
    });

    connect(this, &GameRoom :: downKeyPressed, [&](){
        // qDebug() << machine.pos.x() << " " << machine.pos.y();
        machine.moveDown();
        // qDebug() << "I go down!";
    });
    connect(this, &GameRoom :: leftKeyPressed, [&](){
        machine.moveLeft();
    });
    connect(this, &GameRoom :: rightKeyPressed, [&](){
        machine.moveRight();
    });


    connect(this, &GameRoom :: wKeyPressed, [&](){
        human.moveUp();
    });
    connect(this, &GameRoom :: aKeyPressed, [&](){
        human.moveLeft();
    });
    connect(this, &GameRoom :: sKeyPressed, [&](){
        human.moveDown();
    });
    connect(this, &GameRoom :: dKeyPressed, [&](){
        human.moveRight();
    });
    if(GameModule == 0) {

        // 机器模式





    }



}

void GameRoom :: paintEvent(QPaintEvent *event) {

    Q_UNUSED(event);
    QPixmap buffer(size());
    // buffer.fill(Qt :: transparent);
    QPainter bufferPainter(&buffer);
    QPixmap background(":/RoomBackGround.jpg");
    bufferPainter.drawPixmap(0, 0, this -> width(), this -> height(), background);


    // Draw Game Room

    QPen pen(Qt :: black);
    pen.setWidth(1);
    bufferPainter.setPen(pen);
    for(int i = 0; i < 19; ++i) {
        // bufferPainter.drawLine(Mx + i * gridSize, My + gridSize, Mx + i * gridSize, My + 18 * gridSize);
        // bufferPainter.drawLine(Mx + gridSize, My + i * gridSize, Mx + 18 * gridSize, My + i * gridSize);
        bufferPainter.drawLine(Mx + gridSize, My + (i + 1) * gridSize, Mx + (19) * gridSize, My + (i + 1) * gridSize);
        bufferPainter.drawLine(Mx + (i + 1) * gridSize, My + gridSize, Mx + (i + 1) * gridSize, My + (19) * gridSize);
    }

    // QPixmap centerMap(":/Chess-19.jpeg");
    // bufferPainter.drawPixmap(450, 100, 500, 500, centerMap);




    // Draw Player Icon
    QPixmap machineG(machine.graph);
    bufferPainter.drawPixmap(machine.pos.x() - siz / 2, machine.pos.y() - siz / 2, siz, siz, machineG);
    // qDebug() << "machine : " << machine.pos.x() << ' ' << machine.pos.y();
    // Draw human Player
    QPixmap humanG(human.graph);
    bufferPainter.drawPixmap(human.pos.x() - siz / 2, human.pos.y() - siz / 2, siz, siz, humanG);
    QPainter painter(this);
    painter.drawPixmap(0, 0, buffer);



    // QPainter painter(this);
    // QPixmap pix(":/RoomBackGround.jpg");
    // painter.drawPixmap(0, 0, this -> width(), this -> height(), pix);
    // pix.load(":/Chess-19.jpeg");
    // painter.drawPixmap(450, 100, 500, 500, pix);
}

void GameRoom :: keyPressEvent(QKeyEvent *event) {
    // qDebug() << "I get it!";
    switch(event -> key()) {
    case Qt :: Key_Up:
        emit upKeyPressed();
        // qDebug() << "up";
        break;
    case Qt :: Key_Down:
        emit downKeyPressed();
        // qDebug() << "down";
        break;
    case Qt :: Key_Left:
        emit leftKeyPressed();
        break;
    case Qt :: Key_Right:
        emit rightKeyPressed();
        break;
    case Qt :: Key_W:
        emit wKeyPressed();
        break;
    case Qt :: Key_A:
        emit aKeyPressed();
        break;
    case Qt :: Key_S:
        emit sKeyPressed();
        break;
    case Qt :: Key_D:
        emit dKeyPressed();
        break;
    default:
        break;
    }
}
