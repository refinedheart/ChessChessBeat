#include "settlement.h"

#include <QPushButton>

#include <QLabel>

#include <QPainter>

#include <QPalette>

Settlement::Settlement(QWidget *parent)
    : QWidget{parent}
{
    setFixedSize(1000, 800);
    QPushButton *bckbtn = new QPushButton(this);
    bckbtn->setText("回到模式选择页面");

    QPalette buttonP = bckbtn -> palette();
    buttonP.setColor(QPalette :: ButtonText, Qt :: black);
    bckbtn -> setPalette(buttonP);
    QFont bckFont("宋体", 20, QFont :: Bold);
    connect(bckbtn, &QPushButton :: clicked, [=](){
        qDebug() << "????";
        emit back_to_module();
        qDebug() << "here?";
        this -> close();
    });

    bckbtn -> setFixedSize(300, 200);
    bckbtn -> move(400, 500);
    QLabel *SHeadTitle = new QLabel(this);
    QFont TitleFont("宋体", 30, QFont :: Bold);
    QPalette TitleP = SHeadTitle -> palette();
    TitleP.setColor(QPalette :: WindowText, Qt :: black);
    SHeadTitle -> setPalette(TitleP);


    SHeadTitle -> setFont(TitleFont);
    if(humanScore == 0) {
        SHeadTitle -> setText("Byun Sangil Killed Contest!");
    }
    else {
        SHeadTitle -> setText("柯洁九冠王！");
    }
    SHeadTitle -> move(300, 0);
}

void Settlement :: getHuman(int c) {
    humanScore = c;
}

void Settlement :: getMachine(int c) {
    machineScore = c;
}

void Settlement :: GenerateRoom() {

}

void Settlement :: paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPixmap pix;
    if(humanScore == 0) {
        pix.load(":/MachineWin.webp");
    }
    else {
        pix.load(":/HumanWin.jpg");
    }
    QPainter painter(this);
    painter.drawPixmap(0, 0, this -> width(), this -> height(), pix);
}
