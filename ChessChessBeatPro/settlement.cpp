#include "settlement.h"

#include <QPushButton>

#include <QLabel>

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
    bckbtn -> setFixedSize(200, 100);
    bckbtn -> move(400, 500);
    QLabel *SHeadTitle = new QLabel(this);
    if(humanScore == 0) {
        SHeadTitle -> setText("Machine Killed Contest!");
    }
    else {
        SHeadTitle -> setText("Human Killed Contest!");
    }
}

void Settlement :: getHuman(int c) {
    humanScore = c;
}

void Settlement :: getMachine(int c) {
    machineScore = c;
}

void Settlement :: GenerateRoom() {

}
