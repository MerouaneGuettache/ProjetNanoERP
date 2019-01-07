#include "demandedachat.h"
#include "ui_demandedachat.h"

demandeDachat::demandeDachat(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::demandeDachat)
{
    ui->setupUi(this);
    ui->noStock->setMinimum(1); ui->noStock->setMaximum(4);
    ui->quantite->setMinimum(0);
    ui->prix->setMinimum(0);
}

demandeDachat::~demandeDachat()
{
    delete ui;
}
