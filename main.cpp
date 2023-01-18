#include "mainwindow.h"
#include <QApplication>

template <typename T>
T max(int pocet, T *pole){
    T max = *pole;
    for(int i = 0;i<pocet;i++){
        if(max<pole[i]){
            max = pole[i];
        }
    }
    return max;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
