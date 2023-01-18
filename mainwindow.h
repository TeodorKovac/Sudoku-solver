#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QPushButton>
#include "sudoku.h"
#include <string>

class QTableWidget;
class QTableWidgetItem;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    sudoku *sudoku1;
    QPushButton *vyres;
    QPushButton *nova;
public slots:
    void zmena(int i,int j);
    void res();
    void novy();
signals:
    void cellChanged(int i,int j);
public:
    QTableWidget *tabulka;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
