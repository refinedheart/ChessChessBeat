#ifndef GAMEROOM_H
#define GAMEROOM_H
#include <QWidget>
#include <QMouseEvent>
#include <QLabel>
#include <QPainter>
#include <player.h>
#include <QLineEdit>
#include <QTimer>

#include "chesspiece.h"
#include "chessbox.h"
#include <settlement.h>
class GameRoom : public QWidget
{
    Q_OBJECT
public:
    int getDistance(QPoint machinePos, int id);
    void updateMachinePrint();
    void updateHumanPrint();
    void checkCross();
    void MachineModule();
    bool checkend();
    void updateInformation();
    explicit GameRoom(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    int GameModule;
    QTimer updateTimer;
    Player machine;
    Player human;
    ChessPiece Chess;
    ChessBox boxHuman, boxMachine;
    QLineEdit humanText, machineText;
    Settlement *SR;
private:
    QLabel *label;

protected:
    // void mouseMoveEvent(QMouseEvent *event) override {
    //     // 获取鼠标当前位置的像素坐标
    //     QPoint pos = event->globalPos();

    //     // 更新 QLabel 的文本以显示鼠标坐标
    //     label->setText(QString("Mouse Position: (%1, %2)").arg(pos.x()).arg(pos.y()));
    // }

signals:
    void back_to_select();
    void upKeyPressed();
    void downKeyPressed();
    void leftKeyPressed();
    void rightKeyPressed();
    void wKeyPressed();
    void aKeyPressed();
    void sKeyPressed();
    void dKeyPressed();
};

#endif // GAMEROOM_H
