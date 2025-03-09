#include "moduleselect.h"
#include "gameroom.h"
#include <QPainter>
#include <QLabel>
#include <QFont>
#include <QPushButton>
#include <QPalette>
ModuleSelect::ModuleSelect(QWidget *parent)
    : QWidget{parent}
{
    GameRoom *GR = new GameRoom;
    connect(GR, &GameRoom :: back_to_select, [=](){
        GR -> close();
        this -> show();
    });
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
    machinebtn -> setText("与机器对战！");
    QFont machineFont("宋体", 20, QFont :: Bold);
    machinebtn -> setFont(machineFont);
    machinebtn -> setFixedSize(200, 80);
    machinebtn -> move(300, 400);
    QPalette machineP = machinebtn -> palette();
    machineP.setColor(QPalette :: ButtonText, Qt :: black);
    machinebtn->setPalette(machineP);
    GameRoom *gameroom = new GameRoom;
    connect(machinebtn, &QPushButton :: clicked, [=]() {
        this -> close();
        gameroom -> show();
    });

}

void ModuleSelect :: paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    QPixmap pix(":/Chess-19.jpeg");
    painter.drawPixmap(0, 0, this -> width(), this -> height(), pix);
}
