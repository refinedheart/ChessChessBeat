#ifndef TOOL_H
#define TOOL_H

#include <QWidget>

#include <QApplication>
#include <QMouseEvent>
#include <QLabel>
#include <QVBoxLayout>

class Tool : public QWidget
{
    Q_OBJECT
public:
    // explicit Tool(QWidget *parent = nullptr);
    Tool(QWidget *parent = nullptr) : QWidget(parent) {
        // 创建一个 QLabel 用于显示鼠标坐标
        label = new QLabel("Mouse Position: (0, 0)", this);
        label->setAlignment(Qt::AlignTop);

        // 设置布局
        QVBoxLayout *layout = new QVBoxLayout(this);
        layout->addWidget(label);
        setLayout(layout);

        // 设置窗口大小
        // setFixedSize(400, 300);
        setMouseTracking(true);
    }
protected:
    void mouseMoveEvent(QMouseEvent *event) override {
        // 获取鼠标当前位置的像素坐标
        QPoint pos = event->pos();

        // 更新 QLabel 的文本以显示鼠标坐标
        label->setText(QString("Mouse Position: (%1, %2)").arg(pos.x()).arg(pos.y()));
    }
private:
    QLabel *label;

signals:
};

#endif // TOOL_H
