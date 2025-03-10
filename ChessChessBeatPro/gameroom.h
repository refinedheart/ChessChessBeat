#ifndef GAMEROOM_H
#define GAMEROOM_H
#include <QWidget>
#include <QMouseEvent>
#include <QLabel>
#include <QPainter>
class GameRoom : public QWidget
{
    Q_OBJECT
public:
    explicit GameRoom(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
private:
    QLabel *label;
protected:
    void mouseMoveEvent(QMouseEvent *event) override {
        // 获取鼠标当前位置的像素坐标
        QPoint pos = event->globalPos();

        // 更新 QLabel 的文本以显示鼠标坐标
        label->setText(QString("Mouse Position: (%1, %2)").arg(pos.x()).arg(pos.y()));
    }
signals:
    void back_to_select();
};

#endif // GAMEROOM_H
