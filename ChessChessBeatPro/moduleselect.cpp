#include "moduleselect.h"
#include "gameroom.h"
#include <QPainter>
#include <QLabel>
#include <QFont>
#include <QPushButton>
#include <QPalette>
#include <QDockWidget>
#include <QTextEdit>
ModuleSelect::ModuleSelect(QWidget *parent)
    : QWidget{parent}
{


    /*---------------玩法简介------------------*/

    QPushButton *Intro = new QPushButton(this);

    Intro->setStyleSheet(
        "QPushButton {"
        "   background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FFFFFF, stop: 1 #F0F0F0);" // 白色到浅灰色渐变
        "   border: 2px solid #000000;"
        "   border-radius: 10px;"
        "   padding: 10px 20px;"
        "   color: #000000;"
        "   font-size: 16px;"
        "   box-shadow: 0 2px 4px rgba(0, 0, 0, 0.25);" // 添加阴影，增加立体感
        "}"
        "QPushButton:pressed {"
        "   background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #E0E0E0, stop: 1 #D0D0D0);" // 按下时变暗
        "   box-shadow: 0 1px 2px rgba(0, 0, 0, 0.25);"
        "}"
        );

    Intro -> setText("戳我看玩法！！！");

    Intro -> setFixedSize(200, 50);
    Intro -> move(600, 0);

    connect(Intro, &QPushButton :: clicked, [=](){
        QDockWidget *docw = new QDockWidget("Introduction");
        docw -> setFloating(true);
        QTextEdit *textIntro = new QTextEdit();
        docw -> setWidget(textIntro);
        docw -> show();
        docw -> setFixedSize(800, 800);
        textIntro -> append("游戏玩法介绍：\n");
        textIntro -> setReadOnly(true);
        textIntro -> append("在游戏中，你将进入 LG 杯决赛的赛场，与围棋世界冠军 LG 杯冠军卞相壹进行一场精彩的对决！\n");
        textIntro -> append("玩家将使用经典的 WASD 键来对柯洁头像进行位置移动，对应上左下右的操作。\n");
        textIntro -> append("同时，两位棋手的头顶上方存在计数器，表示再被吃多少颗棋子，他的棋盖就放不下了，根据韩国规则，该棋手判负。\n");
        textIntro -> append("根据 LG 杯第二局，卞相壹棋手执黑棋，柯洁执白棋。故而，您对应的角色只能吃掉对手的棋子，而不能对本方棋子造成影响。\n");
        textIntro -> append("吃子规则也很简单！当您的角色移动到棋盘上的对应位置时，如果位置上有您需要的棋子，它就会被吃掉。\n");
        textIntro -> append("身为韩国围棋常年等级分前三的王牌世界冠军，请不要小瞧他的实力！\n");
        textIntro -> append("我们将提供不同难度的棋手卞相壹供您挑战。\n");
        textIntro -> append("除此之外，您还可以选择双人模式，叫您的小伙伴一起来切磋对抗！\n");
        textIntro -> append("游戏中还可能会出现一些小道具，它们可能是你的救命法宝，也可能是终结比赛的利器，当然也可能是出乎意料的陷阱。\n");
        textIntro -> append("快去探索吧！\n");
    });

    /*---------------------------------------*/

    this -> setFixedSize(800, 700);
    QLabel *SelectHead = new QLabel(this);
    SelectHead -> setText("选择你的模式！");
    QFont SelectFont("宋体", 50, QFont :: Bold);
    QPalette HeadP = SelectHead -> palette();
    HeadP.setColor(QPalette :: WindowText, Qt :: black);
    SelectHead -> setPalette(HeadP);
    SelectHead -> setFont(SelectFont);
    SelectHead -> move(240, 50);
    QPushButton *machinebtn = new QPushButton(this);

    machinebtn->setStyleSheet(
        "QPushButton {"
        "   background-color: #FF6B6B;" // 红色背景，增加视觉冲击力
        "   border: 2px solid #000000;"
        "   border-radius: 10px;"
        "   padding: 10px 20px;"
        "   color: #FFFFFF;"
        "   font-size: 16px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #FF8787;" // 鼠标悬停时变浅
        "}"
        "QPushButton:pressed {"
        "   background-color: #FF5252;" // 按下时变暗
        "}"
        );

    machinebtn -> setText("与机器对战！");
    QFont machineFont("宋体", 20, QFont :: Bold);
    machinebtn -> setFont(machineFont);
    machinebtn -> setFixedSize(200, 80);
    machinebtn -> move(100, 400);
    QPalette machineP = machinebtn -> palette();
    machineP.setColor(QPalette :: ButtonText, Qt :: black);
    machinebtn->setPalette(machineP);


    QPushButton *friendbtn = new QPushButton(this);

    friendbtn->setStyleSheet(
        "QPushButton {"
        "   background-color: #A0522D;" // 鞍棕色背景，复古棋盘颜色
        "   border: 2px solid #8B4513;" // 更深的棕色边框
        "   border-radius: 4px;"
        "   padding: 10px 20px;"
        "   color: #FFFFFF;"
        "   font-size: 16px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #CD853F;" // 鼠标悬停时变亮
        "}"
        "QPushButton:pressed {"
        "   background-color: #8B4513;" // 按下时变暗
        "}"
        );

    friendbtn -> setText("双人对抗！");
    QFont friendFont("宋体", 20, QFont :: Bold);
    friendbtn -> setFont(friendFont);
    friendbtn -> setFixedSize(200, 80);
    friendbtn -> move(500, 400);
    QPalette friendP = friendbtn -> palette();
    friendP.setColor(QPalette :: ButtonText, Qt :: black);
    friendbtn->setPalette(friendP);

    connect(friendbtn, &QPushButton :: clicked, [=](){
        GameRoom *gameroom = new GameRoom(nullptr, 1);
        connect(gameroom, &GameRoom :: back_to_select, [=](){
            gameroom -> close();
            this -> show();
        });
        // gameroom -> GameModule = 1;
        gameroom -> show();
        this -> close();
    });


    connect(machinebtn, &QPushButton :: clicked, [=]() {
        this -> close();
        GameRoom *gameroom = new GameRoom;
        connect(gameroom, &GameRoom :: back_to_select, [=](){
            gameroom -> close();
            this -> show();
        });
        gameroom -> GameModule = 0;
        gameroom -> show();

    });

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
        emit this -> GoBack();
    });
    backbtn -> setFixedSize(200, 80);
    backbtn -> move(300, 600);
}

void ModuleSelect :: paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    QPixmap pix(":/Chess-19.jpeg");
    painter.drawPixmap(0, 0, this -> width(), this -> height(), pix);
}
