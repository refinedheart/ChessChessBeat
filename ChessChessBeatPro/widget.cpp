#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPushButton>
#include <QFont>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this -> setFixedSize(800, 500);
    ui -> StartButton -> setText("对局开始");
    QFont startfont("宋体", 32, QFont :: Bold);
    ui -> StartButton -> setFont(startfont);
    ui -> StartButton -> setFixedSize(200, 120);
    ui -> StartButton -> move(300, 300);
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
