#ifndef SETTLEMENT_H
#define SETTLEMENT_H

#include <QWidget>

#include <player.h>

class Settlement : public QWidget
{
    Q_OBJECT
public:
    explicit Settlement(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;
    int humanScore, machineScore;
    void getHuman(int c);
    void getMachine(int c);
    void GenerateRoom();
    int TrapCalc(int suc, int lac);
    Player machine, human;
    void setPlayer(Player M, Player H);
signals:
    void back_to_module();
    // void paintEvent(QPaintEvent *event);
};

#endif // SETTLEMENT_H
