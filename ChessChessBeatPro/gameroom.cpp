#include "gameroom.h"
#include <QPaintEvent>
#include <QPainter>
#include <QPushButton>
#include <QDebug>
#include "player.h"


#include "chessbox.h"
#include "chesspiece.h"

#include "chessbox.h"

// #include "tool.h"

#include <QLabel>

#include <QPainter>

const int gridSize = 26;
const int Radius = 10;

const int Mx = 450;
const int My = 100;

const int piececnt = 10;


GameRoom::GameRoom(QWidget *parent)
    : QWidget{parent}
{
    // 页面设置
    this->setFocusPolicy(Qt::StrongFocus);
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
        checkCross();
        updateMachinePrint();
    });

    connect(this, &GameRoom :: downKeyPressed, [&](){
        // qDebug() << machine.pos.x() << " " << machine.pos.y();
        machine.moveDown();
        checkCross();
        updateMachinePrint();
        // qDebug() << "I go down!";
    });
    connect(this, &GameRoom :: leftKeyPressed, [&](){
        machine.moveLeft();
        checkCross();
        updateMachinePrint();
    });
    connect(this, &GameRoom :: rightKeyPressed, [&](){
        machine.moveRight();
        checkCross();
        updateMachinePrint();
    });


    connect(this, &GameRoom :: wKeyPressed, [&](){
        human.moveUp();
        checkCross();
        updateHumanPrint();
    });
    connect(this, &GameRoom :: aKeyPressed, [&](){
        human.moveLeft();
        checkCross();
        updateHumanPrint();
    });
    connect(this, &GameRoom :: sKeyPressed, [&](){
        human.moveDown();
        checkCross();
        updateHumanPrint();
    });
    connect(this, &GameRoom :: dKeyPressed, [&](){
        human.moveRight();
        checkCross();
        updateHumanPrint();
    });



    /*---------- generate chess------------*/


    // [1, cnt / 2] = white

    Chess = ChessPiece(piececnt);


    /* ----------generate chess box -------------*/


    boxHuman = ChessBox(30);
    boxMachine = ChessBox(30);

    humanText.setParent(this);
    machineText.setParent(this);
    // limit - scores
    humanText.setText(QString :: number(boxHuman.lim - machine.scores));
    machineText.setText(QString :: number(boxMachine.lim - human.scores));

    QFont humanFont("Roboto", 20, QFont :: Bold);
    QFont machineFont("Consolas", 20, QFont :: Bold);

    humanText.setFont(humanFont);
    machineText.setFont(machineFont);

    humanText.setGeometry(1000, 20, 100, 40);
    machineText.setGeometry(300, 20, 100, 40);
    // humanText.setReadOnly(true);
    // machineText.setReadOnly(true);
    humanText.setFocusPolicy(Qt::NoFocus);
    machineText.setFocusPolicy(Qt::NoFocus);

    humanText.setWindowFlags(Qt::FramelessWindowHint); // 无边框窗口
    machineText.setAttribute(Qt::WA_TranslucentBackground);
    humanText.setStyleSheet(
        "QLineEdit {"
        "   background-color: rgba(255, 255, 255, 0); /* 设置背景颜色为透明 */"
        "   border: none; /* 设置边框样式 */"
        "   color: black; /* 设置文字颜色 */"
        "   padding: 5px; /* 设置内边距 */"
        "}"
    );
    machineText.setStyleSheet(
        "QLineEdit {"
        "   background-color: rgba(255, 255, 255, 0); /* 设置背景颜色为透明 */"
        "   border: none; /* 设置边框样式 */"
        "   color: black; /* 设置文字颜色 */"
        "   padding: 5px; /* 设置内边距 */"
        "}"
    );


    // boxHuman.boxText -> setParent(this);
    // boxHuman.boxText -> setGeometry(20, 20, 20, 20);

    // boxMachine.boxText -> setParent(this);


    // human : white
    // machine : black
    if(GameModule == 0) {

        // 机器模式


        // 策略：减弱来时路的概率后随机


    }



}

void GameRoom :: updateMachinePrint() {
    humanText.setText(QString :: number(boxHuman.lim - machine.scores));
    humanText.update();
    humanText.raise();
    humanText.repaint();
}
void GameRoom :: updateHumanPrint() {
    machineText.setText(QString :: number(boxMachine.lim - human.scores));
    // qDebug() << "Correct Number = " << boxMachine.lim - human.scores;
    // qDebug() << ""
    machineText.update();
    machineText.raise();
    machineText.repaint();
}

void GameRoom :: checkCross() {
    // human: eat black
    for(int i = Chess.blackchess.l; i <= Chess.blackchess.r; ++i) {
        int regx = regetposx(human.pos.x()), regy = regetposy(human.pos.y());
        // qDebug() << "x = " << regx << " y = " << regy;
        if(Chess.Xpos[i] == regx && Chess.Ypos[i] == regy) {
            human.scores ++;
            Chess.regeneratepos(i);
            // qDebug() << "success!";
        }
    }
    for(int i = Chess.whitechess.l; i <= Chess.whitechess.r; ++i) {
        int regx = regetposx(machine.pos.x()), regy = regetposy(machine.pos.y());
        if(Chess.Xpos[i] == regx && Chess.Ypos[i] == regy) {
            machine.scores ++;
            Chess.regeneratepos(i);
            // qDebug() << "Machine points = " << machine.scores;
        }
    }
}

void GameRoom :: paintEvent(QPaintEvent *event) {

    Q_UNUSED(event);
    QPixmap buffer(size());
    // buffer.fill(Qt :: transparent);
    QPainter bufferPainter(&buffer);
    QPixmap background(":/RoomBackGround.jpg");
    bufferPainter.drawPixmap(0, 0, this -> width(), this -> height(), background);


    // Graw chess borad
    bufferPainter.setBrush(Qt :: yellow);
    bufferPainter.drawRect(Mx, My, 20 * gridSize, 20 * gridSize);


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



    // Draw ChessPiece
    bufferPainter.setBrush(Qt :: white);
    for(int i = Chess.whitechess.l; i <= Chess.whitechess.r; ++i) {
        int x = Chess.Xpos[i], y = Chess.Ypos[i];
        QPoint Zp = GetCoordPos(x, y);
        int xx = Zp.x(), yy = Zp.y();
        // (x, y)
        bufferPainter.drawEllipse(xx - Radius, yy - Radius, Radius * 2, Radius * 2);
    }
    bufferPainter.setBrush(Qt :: black);
    for(int i = Chess.blackchess.l; i <= Chess.blackchess.r; ++i) {
        int x = Chess.Xpos[i], y = Chess.Ypos[i];
        QPoint Zp = GetCoordPos(x, y);
        int xx = Zp.x(), yy = Zp.y();
        // (x, y)
        bufferPainter.drawEllipse(xx - Radius, yy - Radius, Radius * 2, Radius * 2);
    }


    // Draw Player Icon
    QPixmap machineG(machine.graph);
    bufferPainter.drawPixmap(machine.pos.x() - siz / 2, machine.pos.y() - siz / 2, siz, siz, machineG);
    // qDebug() << "machine : " << machine.pos.x() << ' ' << machine.pos.y();
    // Draw human Player
    QPixmap humanG(human.graph);
    bufferPainter.drawPixmap(human.pos.x() - siz / 2, human.pos.y() - siz / 2, siz, siz, humanG);
    QPainter painter(this);
    painter.drawPixmap(0, 0, buffer);



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
