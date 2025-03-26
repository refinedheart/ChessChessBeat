#include "gameroom.h"
#include <QPaintEvent>
#include <QPainter>
#include <QPushButton>
#include <QDebug>
#include "player.h"
#include <settlement.h>
#include <QThread>
#include <QFile>
#include <QTextEdit>
#include "chessbox.h"
#include "chesspiece.h"

#include "chessbox.h"

// #include "tool.h"

#include <QLabel>

#include <QPainter>

#include <QDockWidget>

const int gridSize = 26;
const int Radius = 10;

const int Mx = 450;
const int My = 100;

const int piececnt = 10;

const int BoxLimit = 21;

const int MultiTrapV = 20;


const int TrapCntLimit = 3;

int GameRoom :: getDistance(QPoint machinePos, int id) {
    int x = regetposx(machinePos.x()), y = regetposy(machinePos.y());
    return abs(x - Chess.Xpos[id]) + abs(y - Chess.Ypos[id]);
}


GameRoom::GameRoom(QWidget *parent, int Module)
    : QWidget{parent}
{
    // ActivateChess();
    // loadHistory();
    startTime = time(0);
    GameModule = Module;
    // qDebug() << "G = " << GameModule << " M = " << Module;

    // 页面设置
    // qDebug() <<
    this->setFocusPolicy(Qt::StrongFocus);
    this -> setFixedSize(1400, 800);

    SR = new Settlement;
    Trapinq.resize(20);
    for(int i = 0; i < 20; ++i) Trapinq[i].resize(20);
    deadtime = new QTimer*[10];
    for(int i = 0; i < 10; ++i) {
        deadtime[i] = new QTimer(this);
        deadtime[i] -> setSingleShot(true);
    }
    // deadtime.resize(10);
    // std :: vector < QTimer > deadtime;
    // for(int i = 0; i < 10; ++i) {
    //     deadtime[i] = new QTimer(this);
    //     deadtime[i] -> setSingleShot(true);
    // }
    // memset(Trapinq, 0, sizeof Trapinq);
    // timer-update
    updateTimer.setInterval(16);
    connect(&updateTimer, &QTimer :: timeout, [=](){
        update();
    });
    updateTimer.start();

    /*------------------------------------Animation--------------------------------------*/

    // trapAnimation = new QPropertyAnimation(this, "opacity", this);
    // trapAnimation -> setDuration(2000);
    /*------------------------------------------------------------------------------------*/
    // for(int i = 0; i < 10; ++i) deadtime[i].setSingleShot(true);
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

    backbtn->setStyleSheet(
        "QPushButton {"
        "   background-color: #FFFFFF;" // 白色背景，类似白棋
        "   border: 2px solid #000000;" // 黑色边框，模拟棋子边缘
        "   border-radius: 10px;"       // 圆角，使按钮更像棋子
        "   padding: 10px 20px;"
        "   color: #000000;"
        "   font-size: 16px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #F0F0F0;" // 鼠标悬停时变浅
        "}"
        "QPushButton:pressed {"
        "   background-color: #E0E0E0;" // 按下时变暗
        "}"
        );
    QFont backFont("宋体", 16, QFont :: Bold);
    backbtn -> setFont(backFont);
    QPalette backP = backbtn -> palette();
    backP.setColor(QPalette :: ButtonText, Qt :: black);
    backbtn -> setPalette(backP);
    connect(backbtn, &QPushButton :: clicked, [=](){
        emit this -> back_to_select();
        this -> close();
    });
    backbtn -> move(1200, 700);
    backbtn -> setFixedSize(200, 50);



    // LeftTop = (466, 188)
    // Delta d = 26

    machine = Player(":/M-up.png");
    // machine.item -> setParent(this); // A player, up down
    // qDebug() << machine.pos.x() << " " << machine.pos.y();
    human = Player(":/K-up.png", 1);

    int trapnode = 0;


    for(int i = 0; i < TrapCntLimit; ++i) *machine.id[i] = trapnode ++;
    for(int i = 0; i < TrapCntLimit; ++i) *human.id[i] = trapnode ++;
    for(int i = 0; i < TrapCntLimit; ++i) {
        connect(deadtime[*machine.id[i]], &QTimer :: timeout, [=](){
            MRecycleTrap(i);
        });
        connect(deadtime[*human.id[i]], &QTimer :: timeout, [=](){
            HRecycleTrap(i);
        });
    }

    machine.restTraps = TrapCntLimit;
    human.restTraps = TrapCntLimit; // 最多可以布置在场的三个陷阱
    machine.trapScale = human.trapScale = 0;
    // machine.vec.resize(3);
    // human.vec.resize(3);
    // machine.id.resize(3);
    // human.id.resize(3);
    // // scale * staytime = 40

    // for(int i = 0; i < 3; ++i) {
    //     machine.vec[i] = Player :: TrapItem(0, 0, 0, 0);
    //     machine.id[i] = trapnode++;
    //     connect(&deadtime[machine.id[i]], &QTimer :: timeout, [&](){
    //         MRecycleTrap(i);
    //     });
    // }
    // for(int i = 0; i < 3; ++i) {
    //     human.vec[i] = Player :: TrapItem(0, 0, 0, 0);
    //     human.id[i] = trapnode++;
    //     connect(&deadtime[human.id[i]], &QTimer :: timeout, [&](){
    //         HRecycleTrap(i);
    //     });
    // }
    // qDebug() << trapnode;


    // qDebug() << "?????"




    // human.item -> setParent(this); // B player, WASD
    // qDebug() << machine.pos.x() << " " << machine.pos.y();
    connect(this, &GameRoom :: upKeyPressed, [&](){
        machine.moveUp();
        checkCross();
        updateMachinePrint();
        if(checkend()) {
            SR -> show();
            // qDebug() << "continue?";
            this -> close();
            MachineControl.stop();
        }
    });

    /*--------------信号链接------------*/

    connect(this, &GameRoom :: downKeyPressed, [&](){
        // qDebug() << machine.pos.x() << " " << machine.pos.y();
        machine.moveDown();
        checkCross();
        updateMachinePrint();
        if(checkend()) {
            SR -> show();
            // qDebug() << "continue?";
            this -> close();
            MachineControl.stop();
        }
        // qDebug() << "I go down!";
    });
    connect(this, &GameRoom :: leftKeyPressed, [&](){
        machine.moveLeft();
        checkCross();
        updateMachinePrint();
        if(checkend()) {
            SR -> show();
            // qDebug() << "continue?";
            this -> close();
            MachineControl.stop();
        }
    });
    connect(this, &GameRoom :: rightKeyPressed, [&](){
        machine.moveRight();
        checkCross();
        updateMachinePrint();
        if(checkend()) {
            SR -> show();
            // qDebug() << "continue?";
            this -> close();
            MachineControl.stop();
        }
    });


    connect(this, &GameRoom :: wKeyPressed, [&](){
        human.moveUp();
        checkCross();
        updateHumanPrint();
        if(checkend()) {
            SR -> show();
            // qDebug() << "continue?";
            this -> close();
            MachineControl.stop();
        }
    });
    connect(this, &GameRoom :: aKeyPressed, [&](){
        human.moveLeft();
        checkCross();
        updateHumanPrint();
        if(checkend()) {
            SR -> show();
            // qDebug() << "continue?";
            this -> close();
            MachineControl.stop();
        }
    });
    connect(this, &GameRoom :: sKeyPressed, [&](){
        human.moveDown();
        checkCross();
        updateHumanPrint();
        if(checkend()) {
            SR -> show();
            // qDebug() << "continue?";
            this -> close();
            MachineControl.stop();
        }
    });
    connect(this, &GameRoom :: dKeyPressed, [&](){
        human.moveRight();
        checkCross();
        updateHumanPrint();
        if(checkend()) {
            SR -> show();
            // qDebug() << "continue?";
            this -> close();
            // this -> stopAndClose();
            MachineControl.stop();
        }
    });


    connect(this, &GameRoom :: fKeyPressed, [&](){
        // human.LayTrap();
        qDebug() << "WWWWWWW";
        HLayTrap();
        // qDebug() << ">>>>>>>";
    });
    connect(this, &GameRoom :: lKeyPressed, [&](){
        // machine.LayTrap();
        // qDebug() << "wdnmd";
        MLayTrap();
    });

    connect(this, &GameRoom :: pKeyPressed, [&](){
        machine.changeTrapScale();
    });
    connect(this, &GameRoom :: rKeyPressed, [&](){
        human.changeTrapScale();
    });



    /*---------- generate chess------------*/


    // [1, cnt / 2] = white

    Chess = ChessPiece(piececnt, 3);


    /* ----------generate chess box -------------*/


    boxHuman = ChessBox(BoxLimit);
    boxMachine = ChessBox(BoxLimit);

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
    machineText.setGeometry(400, 20, 100, 40);
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
        // qDebug() << "Open Machine Module!";
        // 机器模式

        // 暴力计算确认下一个目标

        // 实现后可以优化随机策略，从而进一步提升 bot 性能
        // Machine 模拟 M 吃白子 用上下左右键移动

        // QTimer MachineControl;

        // qDebug() << "???????";
        // qDebug() << "GameModule = " << GameModule;

        /*--------------------------------------------------------*/
        MachineControl.setInterval(200);
        connect(&MachineControl, &QTimer :: timeout, [&](){
            // qDebug() << "machine move!";
            while(abs(machineMoveX) + abs(machineMoveY) == 0) {
                updateMachineStrategy();
                // qDebug() << "?????";
            }
            if(machineMoveX == 0 || machineMoveY == 0) {
                if(machineMoveX == 0) machineMoveYopt();
                else machineMoveXopt();
            }
            else {
                assert(machineMoveX != 0 && machineMoveY != 0);
                int op = time(0) & 1;
                if(op == 0) machineMoveXopt();
                else machineMoveYopt();
            }
            // qDebug() << "Xpos = " << machineMoveX << " Ypos = " << machineMoveY;
            // qDebug() << "posx = " << machine
        });
        MachineControl.start();
        /*--------------------------------------------------------*/


        // moduleControlThread = new QThread(this);
        // ModuleControlWorker *moduleControlWorker = new ModuleControlWorker(this);
        // moduleControlWorker->moveToThread(moduleControlThread);

        // connect(moduleControlThread, &QThread::started, moduleControlWorker, &ModuleControlWorker::startWork);
        // connect(moduleControlThread, &QThread::finished, moduleControlWorker, &QObject::deleteLater);
        // connect(this, &GameRoom::back_to_select, moduleControlThread, &QThread::quit);

        // moduleControlThread -> start();
    }

    else if(GameModule == 727) {

    }

    connect(SR, &Settlement :: back_to_module, [=](){
        emit back_to_select();
        SR -> close();
        this -> close();
    });


}


void GameRoom :: machineMoveXopt() {
    if(machineMoveX < 0) {
        ++machineMoveX;
        emit leftKeyPressed();
    }
    else {
        --machineMoveX;
        emit rightKeyPressed();
    }
}

void GameRoom :: machineMoveYopt() {
    if(machineMoveY < 0) {
        ++machineMoveY;
        emit upKeyPressed();

    }
    else {
        --machineMoveY;
        emit downKeyPressed();

    }
}

void GameRoom :: updateMachineStrategy() {
    int dis = 1000000000, posid = -1;
    for(int i = Chess.whitechess.l; i <= Chess.whitechess.r; ++i) {
        int nowdis = getDistance(machine.pos, i);
        if(nowdis < dis) {
            dis = nowdis;
            posid = i;
        }
    }
    assert(posid != -1);
    // qDebug() << "id = " << posid;
    machineMoveX = Chess.Xpos[posid] - regetposx(machine.pos.x());
    machineMoveY = Chess.Ypos[posid] - regetposy(machine.pos.y());
}

void GameRoom :: updateInformation() {
    SR -> getHuman(boxHuman.lim - machine.scores);
    SR -> getMachine(boxMachine.lim - human.scores);
}

bool GameRoom :: checkend() {
    // return true; //////////////////////////////////////////
    int numMachine = boxMachine.lim - human.scores;
    int numHuman = boxHuman.lim - machine.scores;
    if(numMachine == 0 || numHuman == 0) {
        updateInformation();
        SR -> GenerateRoom();
        return true;
    }
    else {
        return false;
    }
}


void MachineModule() {
    //
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
            ActivateUnknownIconShow("CHESS");
            // qDebug() << "success!";
        }
    }
    for(int i = Chess.whitechess.l; i <= Chess.whitechess.r; ++i) {
        int regx = regetposx(machine.pos.x()), regy = regetposy(machine.pos.y());
        if(Chess.Xpos[i] == regx && Chess.Ypos[i] == regy) {
            machine.scores ++;
            Chess.regeneratepos(i);
            ActivateUnknownIconShow("CHESS");
            // qDebug() << "Machine points = " << machine.scores;
        }
    }
    for(int i = 0; i < Chess.Itemcnt; ++i) {
        int regx = regetposx(human.pos.x()), regy = regetposy(human.pos.y());
        if(Chess.XS[i] == regx && Chess.YS[i] == regy) {
            machine.Stopcnt += 3;
            Chess.regenerateStopItem(i);
            ActivateUnknownIconShow(("ITEM"));
        }
        regx = regetposx(machine.pos.x()), regy = regetposy(machine.pos.y());
        if(Chess.XS[i] == regx && Chess.YS[i] == regy) {
            human.Stopcnt += 3;
            Chess.regenerateStopItem(i);
            ActivateUnknownIconShow("ITEM");
        }
    }
    for(int i = 0; i < 3; ++i) {
        if(human.pos.x() == machine.vec[i]->x && human.pos.y() == machine.vec[i]->y) {
            ++machine.successTrapcnt;
            human.Stopcnt += machine.vec[i]->val;
            MRecycleTrap(i);
            ActivateUnknownIconShow("TRAP");
        }
        if(machine.pos.x() == human.vec[i]->x && machine.pos.y() == human.vec[i]->y) {
            ++human.successTrapcnt;
            machine.Stopcnt += human.vec[i]->val;
            HRecycleTrap(i);
            ActivateUnknownIconShow("TRAP");
        }
    }
}

void GameRoom :: paintEvent(QPaintEvent *event) {
    // assert(0);
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
        bufferPainter.drawEllipse(xx - Radius, yy - Radius, Radius << 1, Radius << 1);
    }
    bufferPainter.setBrush(Qt :: black);
    for(int i = Chess.blackchess.l; i <= Chess.blackchess.r; ++i) {
        int x = Chess.Xpos[i], y = Chess.Ypos[i];
        QPoint Zp = GetCoordPos(x, y);
        int xx = Zp.x(), yy = Zp.y();
        // (x, y)
        bufferPainter.drawEllipse(xx - Radius, yy - Radius, Radius << 1, Radius << 1);
    }

    qDebug() << time(0) - startTime;
    // if(abs(time(0) - startTime) >= 1000) {
        for(int i = 0; i < Chess.Itemcnt; ++i) {
            int x = Chess.XS[i], y = Chess.YS[i];
            bufferPainter.setPen(Qt :: red);
            QPoint Zp = GetCoordPos(x, y);
            int xx = Zp.x(), yy = Zp.y();
            for(int k = 0; k < 3; ++k) {
                int r = Radius >> k;
                bufferPainter.drawEllipse(xx - r, yy - r, r << 1, r << 1);
            }
        }
    // }


    // Draw Trap

    bufferPainter.setPen(Qt :: gray);
    bufferPainter.setBrush(Qt :: NoBrush);
    for(int i = 0; i < TrapCntLimit; ++i) {
        int x = machine.vec[i]->x, y = machine.vec[i]->y;
        if(x == 0 && y == 0) continue;
        bufferPainter.drawRect(x - Radius, y - Radius, Radius << 1, Radius << 1);
    }
    for(int i = 0; i < TrapCntLimit; ++i) {
        int x = human.vec[i]->x, y = human.vec[i]->y;
        if(x == 0 && y == 0) continue;
        bufferPainter.drawRect(x - Radius, y - Radius, Radius << 1, Radius << 1);
    }
    // qDebug() << "Drawed the trap";
    // Draw Player Icon
    QPixmap machineG(machine.graph);
    bufferPainter.drawPixmap(machine.pos.x() - siz / 2, machine.pos.y() - siz / 2, siz, siz, machineG);
    // qDebug() << "machine : " << machine.pos.x() << ' ' << machine.pos.y();
    // Draw human Player
    QPixmap humanG(human.graph);
    bufferPainter.drawPixmap(human.pos.x() - siz / 2, human.pos.y() - siz / 2, siz, siz, humanG);

    QPixmap Box(":/ChessBox.png");
    bufferPainter.drawPixmap(200, 0, 220, 140, Box);
    bufferPainter.drawPixmap(1000, 0, 220, 140, Box);


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
    case Qt :: Key_F:
        emit fKeyPressed();
        break;
    case Qt :: Key_L:
        emit lKeyPressed();
        break;
    case Qt :: Key_P:
        emit pKeyPressed();
        break;
    case Qt :: Key_R:
        emit rKeyPressed();
        break;
    default:
        break;
    }
}

GameRoom :: ~GameRoom() {
    // if (moduleControlThread->isRunning()) {
    //     moduleControlThread->quit();
    //     moduleControlThread->wait();
    // }
    // delete moduleControlThread;
}

void GameRoom :: MLayTrap() {
    if(machine.restTraps == 0) return ;
    int rx = regetposx(machine.pos.x());
    int ry = regetposy(machine.pos.y());
    if(Trapinq[rx][ry]) return ;
    Trapinq[rx][ry] = 1;
    ++machine.layTrapcnt;
    --machine.restTraps;
    int goalpos = 0;
    while(machine.vec[goalpos]->flag != 0) ++goalpos;
    assert(goalpos < TrapCntLimit);
    int ID = *machine.id[goalpos];
    *machine.vec[goalpos] = Player :: TrapItem(2, TrapScaleVal[machine.trapScale], machine.pos.x(), machine.pos.y());
    deadtime[ID] -> setInterval(1000 * MultiTrapV / TrapScaleVal[machine.trapScale]);
    deadtime[ID] -> start();
}

void GameRoom :: HLayTrap() {
    if(human.restTraps == 0) return ;
    int rx = regetposx(human.pos.x());
    int ry = regetposy(human.pos.y());
    if(Trapinq[rx][ry]) return ;
    // qDebug() << "!!!!";
    // qDebug() << "wdnmd";
    Trapinq[rx][ry] = 1;
    --human.restTraps;
    ++human.layTrapcnt;
    int goalpos = 0;
    while(human.vec[goalpos]->flag != 0) ++goalpos;
    // qDebug() << "goal = " << goalpos;
    assert(goalpos < TrapCntLimit);
    int ID = *human.id[goalpos];
    *human.vec[goalpos] = Player :: TrapItem(2, TrapScaleVal[human.trapScale], human.pos.x(), human.pos.y());
    deadtime[ID] -> setInterval(1000 * MultiTrapV / TrapScaleVal[human.trapScale]);
    deadtime[ID] -> start();
}

void GameRoom :: MRecycleTrap(int x) {
    // machine.vec[x]
    deadtime[*machine.id[x]] -> stop();
    int rx = regetposx(machine.vec[x]->x);
    int ry = regetposy(machine.vec[x]->x);
    Trapinq[rx][ry] = 0;
    *machine.vec[x] = Player :: TrapItem(0, 0, 0, 0);
    machine.restTraps++;
}

void GameRoom :: HRecycleTrap(int x) {
    deadtime[*human.id[x]] -> stop();
    int rx = regetposx(human.vec[x]->x);
    int ry = regetposy(human.vec[x]->x);
    Trapinq[rx][ry] = 0;
    *human.vec[x] = Player :: TrapItem(0, 0, 0, 0);
    human.restTraps++;
}

void GameRoom :: loadHistory() {
    nowHistory.clear();
    QFile fileee("history.txt");
    if(fileee.open(QFile :: ReadOnly | QFile :: Text)) {
        QTextStream inrrr(&fileee);
        while(!inrrr.atEnd()) {
            QString linenow = inrrr.readLine();
            nowHistory << linenow;
        }
        fileee.close();
    }
}

void GameRoom :: ActivateChess() {
    QDockWidget *chessDoc = new QDockWidget("Chess Introduce");
    chessDoc -> setFloating(true);
    QTextEdit *textnow = new QTextEdit();
    textnow -> setReadOnly(true);
    chessDoc -> show();
    chessDoc -> setWidget(textnow);
    chessDoc -> setFixedSize(800, 800);
}

void GameRoom :: ActivateItem() {
    QDockWidget *chessDoc = new QDockWidget("Item Introduce");
    chessDoc -> setFloating(true);
    QTextEdit *textnow = new QTextEdit();
    textnow -> setReadOnly(true);
    chessDoc -> show();
    chessDoc -> setWidget(textnow);
    chessDoc -> setFixedSize(800, 800);
}

void GameRoom :: ActivateTrap() {
    QDockWidget *chessDoc = new QDockWidget("Trap Introduce");
    chessDoc -> setFloating(true);
    QTextEdit *textnow = new QTextEdit();
    textnow -> setReadOnly(true);
    chessDoc -> show();
    chessDoc -> setWidget(textnow);
    chessDoc -> setFixedSize(800, 800);
}

void GameRoom :: ActivateUnknownIconShow(QString qwq) {
    loadHistory();

}

// qreal GameRoom :: opacity() const {
//     return m_opacity;
// }

// void GameRoom :: setOpacity(qreal opacity) {
//     m_opacity = opacity;
//     update();
// }
