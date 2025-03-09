#include "moduleselect.h"
#include "gameroom.h"
#include <QPainter>
#include <QLabel>
#include <QFont>
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
    SelectHead -> setFont(SelectFont);
    SelectHead -> move(240, 50);
}

void ModuleSelect :: paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    QPixmap pix(":/Chess-19.jpeg");
    painter.drawPixmap(0, 0, this -> width(), this -> height(), pix);
}
