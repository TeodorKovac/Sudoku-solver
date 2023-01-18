#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QVBoxLayout>
#include <QString>
#include <QSize>
#include <QColor>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setFixedSize(350,500);
    ui->setupUi(this);
    tabulka = new QTableWidget(this);
    sudoku1 = new sudoku();
    tabulka->setRowCount(9);
    tabulka->setColumnCount(9);
    tabulka->horizontalHeader()->setVisible(false);
    tabulka->verticalHeader()->setVisible(false);
    for(int i = 0;i<9;i++){
        for(int j = 0;j<9;j++){
            tabulka->setItem(i,j,new QTableWidgetItem("000 \n"));

        }
    }
    QColor color(196, 197, 201);
    for(int i = 0; i<3;i++){
        for(int j = 0;j<3;j++){
            tabulka->item(i,j)->setBackgroundColor(color);
        }
    }
    for(int i = 0; i<3;i++){
        for(int j = 6;j<9;j++){
            tabulka->item(i,j)->setBackgroundColor(color);
        }
    }
    for(int i = 6; i<9;i++){
        for(int j = 0;j<3;j++){
            tabulka->item(i,j)->setBackgroundColor(color);
        }
    }
    for(int i = 6; i<9;i++){
        for(int j = 6;j<9;j++){
            tabulka->item(i,j)->setBackgroundColor(color);
        }
    }
    for(int i = 3; i<6;i++){
        for(int j = 3;j<6;j++){
            tabulka->item(i,j)->setBackgroundColor(color);
        }
    }

    vyres = new QPushButton("&Vyres",this);
    nova = new QPushButton("&Restart",this);

    tabulka->setMinimumHeight(317);
    tabulka->setMaximumHeight(317);
    tabulka->setMinimumWidth(327);
    tabulka->setMaximumWidth(327);
    tabulka->resizeRowsToContents();
    tabulka->resizeColumnsToContents();
    //QSize size (20,20);
    for(int i = 0;i<9;i++){
        for(int j = 0;j<9;j++){
            tabulka->item(i,j)->setText("0");
            tabulka->item(i,j)->setTextAlignment(Qt::AlignJustify);
            //tabulka->item(i,j)->setTextAlignment(Qt::AlignVCenter);
        }
    }
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(tabulka);
    layout->addWidget(vyres);
    layout->addWidget(nova);

    connect(tabulka,SIGNAL(cellChanged(int,int)),this,SLOT(zmena(int,int)));
    connect(vyres,SIGNAL(clicked(bool)),this,SLOT(res()));
    connect(nova,SIGNAL(clicked(bool)),this,SLOT(novy()));

    QWidget *window = new QWidget();
    window->setLayout(layout);
    setCentralWidget(window);

}

void MainWindow::zmena(int i,int j){
    int cislo = this->tabulka->item(i,j)->text().toInt();
    if(sudoku1->zkusSet(i,j,cislo)){
        sudoku1->set(i,j,cislo);
    }else{
        tabulka->item(i,j)->setText("0");
    }
}

void MainWindow::novy(){
    sudoku1->reset();
    for(int i=0;i<9;i++){
        for(int j = 0;j<9;j++){
            tabulka->item(i,j)->setText("0");
        }
    }
}

void MainWindow::res(){
    bool ok;
    ok = sudoku1->vyres();
    if(ok){
        for(int i=0;i<9;i++){
            for(int j = 0;j<9;j++){
                QString text;
                text = QString::number(sudoku1->tabulka1[i][j]);
                tabulka->item(i,j)->setText(text);
            }
        }
    }else{
        QMessageBox msgBox;
        msgBox.setText("Zadané sudoku nemá řešení");
        msgBox.exec();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
