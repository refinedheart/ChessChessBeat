#include "suspendfunction.h"
#include <QEventLoop>
#include <QDockWidget>
#include <QObject>

SuspendFunction::SuspendFunction() {}

void SuspendFunction :: Suspend(QDockWidget* chessDoc) {
    QEventLoop eventLoop;

    // 连接 QDockWidget 的 visibilityChanged 信号到槽函数
    connect(chessDoc, &QDockWidget::visibilityChanged, this, [&](bool vis) {
        if (!vis) {
            // 关闭窗口并退出事件循环
            chessDoc->close();
            eventLoop.exit();
        }
    });

    // 进入事件循环
    eventLoop.exec();
}
