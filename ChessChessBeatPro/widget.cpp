#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this -> setFixedSize(800, 500);

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
