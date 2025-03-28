#ifndef SUSPENDFUNCTION_H
#define SUSPENDFUNCTION_H

#include <QDockWidget>

class SuspendFunction : public QObject
{
    Q_OBJECT
public:
    SuspendFunction();
    void Suspend(QDockWidget* chessDoc);
};

#endif // SUSPENDFUNCTION_H
