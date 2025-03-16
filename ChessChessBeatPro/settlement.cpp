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
    buttonP.setColor(QPalette :: ButtonText, Qt :: green);
    bckbtn -> setPalette(buttonP);
    bckbtn->setStyleSheet(
        "QPushButton {"
        "   border: 2px solid red;" // 设置边框为2像素宽的红色实线
        "   border-radius: 4px;"    // 设置边框圆角半径
        "   padding: 5px;"          // 设置内边距
        "}"
        "QPushButton:hover {"
        "   background-color: lightgray;" // 鼠标悬停时的背景颜色
        "}"
        );
    QFont bckFont("宋体", 20, QFont :: Bold);
    connect(bckbtn, &QPushButton :: clicked, [=](){
        qDebug() << "????";
        emit back_to_module();
        qDebug() << "here?";
        this -> close();
    });

    bckbtn -> setFixedSize(300, 100);
    bckbtn -> move(350, 500);
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
