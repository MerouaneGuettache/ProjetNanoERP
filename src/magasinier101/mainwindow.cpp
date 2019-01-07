#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    da(new Ui::demandeDachat)
{
    ui->setupUi(this);
    widget = new QWidget;
    da->setupUi(widget);
    ui->horizontalLayout_2->addWidget(widget);

    //connect to the database:
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("db4free.net");
    db.setDatabaseName("test_merouane");
    db.setUserName("merouane");
    db.setPassword("merouane");
    bool ok = db.open();
    if (ok) qDebug() << "hallelujah !";
    else qDebug() << "failed to open";

    sqlModele = new QSqlQueryModel();
    sqlModele->setQuery("SELECT * FROM demandeDachat");

    //connecting signals to slots
    connect(ui->pushButton_3 ,SIGNAL(clicked()),this,SLOT(afficherDemande()));
    connect(ui->pushButton_2 ,SIGNAL(clicked()), this,SLOT(afficherTable()));
    connect(da->buttonEnvoyer,SIGNAL(clicked()), this, SLOT(envoyerDemande()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::afficherDemande()
{
    QLayoutItem *wd;
    while(wd = ui->horizontalLayout_2->takeAt(0))
    {
        delete wd->widget();
        delete wd;
    }
    widget = new QWidget;
    da->setupUi(widget);
    ui->horizontalLayout_2->addWidget(widget);
    connect(da->buttonEnvoyer,SIGNAL(clicked()), this, SLOT(envoyerDemande()));
}

void MainWindow::afficherTable()
{
    QLayoutItem *wd;
    while(wd = ui->horizontalLayout_2->takeAt(0))
    {
        delete wd->widget();
        delete wd;
    }
    sqlModele->setQuery("SELECT * FROM demandeDachat");
    vue = new QTableView;
    vue->setModel(sqlModele);
    ui->horizontalLayout_2->addWidget(vue);
}

void MainWindow::envoyerDemande()
{
    QSqlQuery query;
    query.prepare("INSERT INTO demandeDachat (id, noStock, article, quantite, prix, note) "
                  "VALUES (NULL, ?, ?, ?, ?, ?)");

    query.addBindValue(da->noStock->value());
    query.addBindValue(da->article->currentText());
    query.addBindValue(da->quantite->value());
    query.addBindValue(da->prix->value());
    query.addBindValue(da->note->toPlainText());
    if(query.exec())qDebug() <<"query execute succefully" ;
    else qDebug() <<"failed to execute";
}
