#ifndef MODULESELECT_H
#define MODULESELECT_H

#include <QWidget>

class ModuleSelect : public QWidget
{
    Q_OBJECT
public:
    explicit ModuleSelect(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
signals:
    void GoBack();
};

#endif // MODULESELECT_H
