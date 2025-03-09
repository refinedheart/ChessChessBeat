#ifndef GAMEROOM_H
#define GAMEROOM_H
#include <QWidget>
class GameRoom : public QWidget
{
    Q_OBJECT
public:
    explicit GameRoom(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
signals:
};

#endif // GAMEROOM_H
