#include "settlement.h"

#include <QPushButton>

#include <QLabel>

#include <QPainter>

#include <QPalette>


#include <QDockWidget>

#include <QTableWidget>

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
    QFont bckFont("宋体", 30, QFont :: Bold);
    bckbtn -> setFont(bckFont);
    connect(bckbtn, &QPushButton :: clicked, [=](){
        // qDebug() << "????";
        emit back_to_module();
        // qDebug() << "here?";
        this -> close();
    });

    bckbtn -> setFixedSize(300, 100);
    bckbtn -> move(350, 600);
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


    QPushButton *recordbtn = new QPushButton(this);

    recordbtn -> setText("本场表现");

    QFont recordFont = QFont("宋体", 25, QFont :: Bold);

    recordbtn -> setFont(recordFont);

    recordbtn -> move(380, 500);

    recordbtn -> setFixedSize(200, 50);

    QPalette recordP = recordbtn -> palette();
    QColor goldC(225, 215, 0);
    recordP.setColor(QPalette :: ButtonText, goldC);
    recordbtn -> setPalette(recordP);


    recordbtn->setStyleSheet(
        "QPushButton {"
        "   background-color: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 #FFD700, stop: 1 #FFA500);" // 金色渐变背景
        "   color: white;" // 文字颜色为白色
        "   border: none;" // 去掉边框
        "   border-radius: 10px;" // 圆角
        "   padding: 10px 20px;" // 内边距
        "   font-family: 'Arial';" // 字体
        "   font-size: 16px;" // 字号
        "   font-weight: bold;" // 粗体
        "}"
        "QPushButton:hover {"
        "   background-color: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 #FFA500, stop: 1 #FF8C00);" // 悬停时的渐变背景
        "}"
        "QPushButton:pressed {"
        "   background-color: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 #FF8C00, stop: 1 #FF7F00);" // 按下时的渐变背景
        "}"
        );


    connect(recordbtn, &QPushButton :: clicked, [&](){
        QDockWidget *countDoc = new QDockWidget("Final Record");

        QTableWidget *table = new QTableWidget(2, 3);
        for(int i = 0; i < 2; ++i) {
            for(int j = 0; j < 3; ++j) {
                QTableWidgetItem *item = new QTableWidgetItem;
                item->setTextAlignment(Qt::AlignCenter);
                table -> setItem(i, j, item);
            }
        }
        table->setHorizontalHeaderLabels(QStringList() << "Player" << "Score" << "Points");
        table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        table -> item(0, 0) -> setText("卞相壹");
        table -> item(1, 0) -> setText("柯洁");
        table -> item(0, 1) -> setText(QString :: number(machineScore));
        table -> item(1, 1) -> setText(QString :: number(humanScore));
        // 调整列宽以适应内容
        table->resizeColumnsToContents();

        // 将表格添加到 QDockWidget 中
        countDoc->setWidget(table);
        countDoc -> show();
    });

    // 做一个包括反应时间、道具使用等的数据统计表格



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
