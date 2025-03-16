#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPushButton>
#include <QFont>
#include <QPalette>
#include "moduleselect.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this -> setFixedSize(800, 500);
    ui -> StartButton -> setText("对局开始");

    ui->StartButton->setStyleSheet(
        "QPushButton {"
        "   background-color: #F5F5DC;" // 米色背景，类似棋盘颜色
        "   border: 2px solid #000000;" // 黑色边框，模拟棋盘网格
        "   border-radius: 8px;"
        "   padding: 15px 30px;"
        "   color: #000000;"
        "   font-size: 20px;"
        "   font-weight: bold;"
        "}"
        "QPushButton:hover {"
        "   background-color: #E8E8E8;" // 鼠标悬停时变浅
        "}"
        "QPushButton:pressed {"
        "   background-color: #D8D8D8;" // 按下时变暗
        "}"
        );

    QFont startfont("宋体", 32, QFont :: Bold);
    ui -> StartButton -> setFont(startfont);
    ui -> StartButton -> setFixedSize(200, 100);
    ui -> StartButton -> move(300, 350);
    ui -> StartHeadTitle -> setText("Chess Chess Beat");
    QFont HeadFont("宋体", 50, QFont :: Bold);
    ui -> StartHeadTitle -> setFont(HeadFont);
    ui -> StartHeadTitle -> setFixedSize(600, 40);
    ui -> StartHeadTitle -> move(170, 30);
    QPalette HeadP = ui -> StartHeadTitle -> palette();
    HeadP.setColor(QPalette :: WindowText, Qt :: red);
    ui -> StartHeadTitle -> setPalette(HeadP);
    ModuleSelect *SR = new ModuleSelect;
    connect(SR, &ModuleSelect :: GoBack, [=](){
        SR -> close();
        this -> show();
    });
    connect(ui -> StartButton, &QPushButton :: clicked, [=](){
        this -> close();
        SR -> show();
    });

}

Widget::~Widget()
{
    delete ui;
}

void Widget :: paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    QPixmap pix(":/start-background.webp");
    painter.drawPixmap(0, 0, this -> width(), this -> height(), pix);
}
