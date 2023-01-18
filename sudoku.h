#ifndef SUDOKU_H
#define SUDOKU_H
#include <math.h>


class sudoku
{
    enum{DIM=9};
    void alokujPamet();
public:
    int **tabulka1;
    sudoku();
    void set(int x, int y, int hodnota);
    bool resitelny();
    bool vyreseny(); //pokud bude vyreseny, vrati 1
    bool vyres();
    //void zkus(int x, int y, int cislo);
    bool testBox(int x, int y, int num);
    bool zkusSet(int x, int y, int hodnota);
    void vypis();
    void reset();
};

#endif // SUDOKU_H
