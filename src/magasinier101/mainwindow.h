#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "demandedachat.h"
#include "ui_demandedachat.h"
#include <QStandardItem>
#include <QTableView>

#include <QtGui>
#include <QtSql>
#include <QtCore>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void afficherDemande();
    void afficherTable();
    void envoyerDemande();

private:
    Ui::MainWindow *ui;
    Ui::demandeDachat *da;
    QWidget *widget;
    QSqlQueryModel *sqlModele;
    QTableView *vue;
};

#endif // MAINWINDOW_H
