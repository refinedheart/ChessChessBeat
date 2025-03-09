#include "moduleselect.h"
#include "gameroom.h"
ModuleSelect::ModuleSelect(QWidget *parent)
    : QWidget{parent}
{
    GameRoom *GR = new GameRoom;
    connect(GR, &GameRoom :: back_to_select, [=](){
        GR -> close();
        this -> show();
    });

}
