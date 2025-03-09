#include "moduleselect.h"
#include "gameroom.h"
#include <QPainter>
ModuleSelect::ModuleSelect(QWidget *parent)
    : QWidget{parent}
{
    GameRoom *GR = new GameRoom;
    connect(GR, &GameRoom :: back_to_select, [=](){
        GR -> close();
        this -> show();
    });
    this -> setFixedSize(800, 700);

}

void ModuleSelect :: paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    QPixmap pix(":/Chess-19.jpeg");
    painter.drawPixmap(0, 0, this -> width(), this -> height(), pix);
}
