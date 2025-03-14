#include "settlement.h"

#include <QPushButton>

Settlement::Settlement(QWidget *parent)
    : QWidget{parent}
{
    setFixedSize(1000, 800);
    QPushButton *bckbtn = new QPushButton(this);
    bckbtn->setText("回到模式选择页面");
    connect(bckbtn, &QPushButton :: clicked, [=](){
        emit back_to_module();
        this -> close();
    });
    bckbtn -> setFixedSize(100, 30);
}

void Settlement :: getHuman(int c) {
    humanScore = c;
}

void Settlement :: getMachine(int c) {
    machineScore = c;
}

void Settlement :: GenerateRoom() {

}
