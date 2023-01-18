#include "sudoku.h"
#include <math.h>
#include <iostream>

sudoku::sudoku()
{
    alokujPamet();
    for(int i = 0; i<DIM;i++)
        for(int j = 0; j<DIM; j++)
            tabulka1[i][j]=0;
}

void sudoku::alokujPamet(){
    tabulka1 = new int*[DIM];
    for(int i = 0; i<DIM;i++){
        tabulka1[i] = new int[DIM];
    }
}

bool sudoku::vyreseny(){
    for(int i = 0;i<DIM;i++){
        for(int j = 0;j<DIM;j++){
            if(tabulka1[i][j]==0){
                return false;
            }
        }
    }
    return true;
}


void sudoku::set(int x, int y, int hodnota){
    bool lzeRadek = true,lzeSloupec = true,lzeBox = true;
    for(int i = 0;i<DIM;i++){
        if(tabulka1[i][y]==hodnota){
            lzeSloupec = false;
        }
    }
    for(int j = 0;j<DIM;j++){
        if(tabulka1[x][j]==hodnota){
            lzeRadek = false;
        }
    }
    if(!testBox(x,y,hodnota)){
        lzeBox = false;
    }
if(lzeBox && lzeRadek && lzeSloupec){
    tabulka1[x][y]=hodnota;
}


    //tabulka1[x-1][y-1]=hodnota;
}

bool sudoku::zkusSet(int x, int y, int hodnota){
    set(x,y,hodnota);
    if(tabulka1[x][y]==hodnota){
        return true;
    }else{
        return false;
    }
}
bool sudoku::testBox(int x, int y, int num){
    int i = x/3;
    int j = y/3;
    if(i<1){
        if(j<1){
            for(int k = 0;k<3;k++){
                for(int l = 0;l<3;l++){
                    if(tabulka1[k][l]==num){
                        return false;
                    }
                }
            }
        }else if(j>=1 && j<2){
            for(int k = 0;k<3;k++){
                for(int l = 3;l<6;l++){
                    if(tabulka1[k][l]==num){
                        return false;
                    }
                }
            }
        }else if(j>=2 && j<3){
            for(int k = 0;k<3;k++){
                for(int l = 6;l<9;l++){
                    if(tabulka1[k][l]==num){
                        return false;
                    }
                }
            }
        }
    }else if(i>=1 && i<2){
        if(j<1){
            for(int k = 3;k<6;k++){
                for(int l = 0;l<3;l++){
                    if(tabulka1[k][l]==num){
                        return false;
                    }
                }
            }
        }else if(j>=1 && j<2){
            for(int k = 3;k<6;k++){
                for(int l = 3;l<6;l++){
                    if(tabulka1[k][l]==num){
                        return false;
                    }
                }
            }
        }else if(j>=2 && j<3){
            for(int k = 3;k<6;k++){
                for(int l = 6;l<9;l++){
                    if(tabulka1[k][l]==num){
                        return false;
                    }
                }
            }
        }

    }else if(i>=2 && i<3){
        if(j<1){
            for(int k = 6;k<9;k++){
                for(int l = 0;l<3;l++){
                    if(tabulka1[k][l]==num){
                        return false;
                    }
                }
            }
        }else if(j>=1 && j<2){
            for(int k = 6;k<9;k++){
                for(int l = 3;l<6;l++){
                    if(tabulka1[k][l]==num){
                        return false;
                    }
                }
            }
        }else if(j>=2 && j<3){
            for(int k = 6;k<9;k++){
                for(int l = 6;l<9;l++){
                    if(tabulka1[k][l]==num){
                        return false;
                    }
                }
            }
        }
    }
return true;
}

bool sudoku::vyres(){
    int ukazatel = 0;
    int cislo = 1;
    int x,y;

    int volnaMista = 0;
    for(int i = 0;i<DIM;i++){
        for(int j = 0;j<DIM;j++){
            if(tabulka1[i][j]==0){
                volnaMista++;

            }
        }
    }
    int souradniceX[volnaMista];
    int souradniceY[volnaMista];
    for(int i = 0;i<DIM;i++){
        for(int j = 0;j<DIM;j++){
            if(tabulka1[i][j]==0){
                souradniceX[ukazatel]=i;
                souradniceY[ukazatel]=j;
                ukazatel++;
            }
        }
    }
    ukazatel = 0;
    while(ukazatel<volnaMista){
        x=souradniceX[ukazatel];
        y=souradniceY[ukazatel];
        if(cislo<10){
            if(zkusSet(x,y,cislo)){
                set(x,y,cislo);
                ukazatel++;
                cislo = 1;
            }else if(cislo==9){
                if(ukazatel==0){
                    return false;
                }else{
                    tabulka1[x][y]=0;
                    ukazatel--;
                    cislo = tabulka1[souradniceX[ukazatel]][souradniceY[ukazatel]]+1;
                }
            }else{
                cislo++;
            }
        }
        else{
            tabulka1[x][y]=0;
            ukazatel--;
            cislo = tabulka1[souradniceX[ukazatel]][souradniceY[ukazatel]]+1;
        }
        //this->vypis();
    }
    return true;
}

void sudoku::vypis(){
    for(int i = 0;i<DIM;i++){
        for(int j = 0;j<DIM;j++){
            std::cout <<" "<< tabulka1[i][j] <<" ";
        }
        std::cout << std::endl;
    }
}
void sudoku::reset(){
    for(int i = 0;i<DIM;i++){
        for(int j = 0;j<DIM;j++){
            tabulka1[i][j]=0;
        }
    }
}
