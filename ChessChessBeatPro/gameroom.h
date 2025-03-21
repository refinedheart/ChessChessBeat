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
#include <vector>
#include <QPropertyAnimation>
class GameRoom : public QWidget
{
    Q_OBJECT
    // Q_PROPERTY(qreal opacity READ opacity WRITE setOpacity)
public:
    int getDistance(QPoint machinePos, int id);
    void updateMachinePrint();
    void updateHumanPrint();
    void checkCross();
    void MachineModule();
    bool checkend();
    void updateInformation();
    void updateMachineStrategy();
    void machineMoveXopt();
    void machineMoveYopt();
    void MLayTrap();
    void HLayTrap();
    void MRecycleTrap(int x);
    void HRecycleTrap(int x);
    explicit GameRoom(QWidget *parent = nullptr, int Module = 0);
    ~GameRoom();
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    int GameModule;
    int machineMoveX, machineMoveY;
    std :: vector < std :: vector < int > > Trapinq;

    // QThread *moduleControlThread = nullptr;
    QTimer updateTimer, MachineControl;
    Player machine;
    Player human;
    ChessPiece Chess;
    ChessBox boxHuman, boxMachine;
    QLineEdit humanText, machineText;
    Settlement *SR;
    QTimer **deadtime = nullptr;
    // qreal m_opacity;
    // QPropertyAnimation *trapAnimation;

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
    void fKeyPressed();
    void lKeyPressed();
    void pKeyPressed();
    void rKeyPressed();
};

#endif // GAMEROOM_H
