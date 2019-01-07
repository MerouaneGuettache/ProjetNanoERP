#ifndef DEMANDEDACHAT_H
#define DEMANDEDACHAT_H

#include <QWidget>

namespace Ui {
class demandeDachat;
}

class demandeDachat : public QWidget
{
    Q_OBJECT

public:
    explicit demandeDachat(QWidget *parent = nullptr);
    ~demandeDachat();

private:
    Ui::demandeDachat *ui;
};

#endif // DEMANDEDACHAT_H
