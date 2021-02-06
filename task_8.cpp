/*
1. To tables of points A[w] [k] and B[w] [k] (w, k - constants) draw points - records with
integer fields (x, y) such that the coordinates (x, y) on the perimeter of array A are
one-digit, and inside the table - from the range <-20, 20>, while in the table B -
reverse draw
2. Print each table in rows in a legible way.
3. In table A, replace the x-coordinates of the points in column 2 with the positive mean
x coordinates in this column (if any), and in table B the x coordinates of the points
in column 4, replace the average of the x values greater than the constant G in that column.
4. Reprint both tables and the number of changes made to both tables
together.
*/

#include <iostream>
#include <time.h>

using namespace std;

const int w = 5;
const int k = 6;

int liczba_zmian=0;

struct Punkt{
    int x;
    int y;
};


void wypelnij(Punkt punkty[w][k], int cala_tab, int obwodzik)
{
    srand(time(NULL));

    for(int i=0; i<w; i++){
        for(int j=0; j<k; j++){
            punkty[i][j].x = rand()%cala_tab;
            punkty[i][j].y = rand()%cala_tab;
            if(rand()%2==0){
            punkty[i][j].x = punkty[i][j].x * -1;
            }
            if(rand()%2==0){
            punkty[i][j].y = punkty[i][j].y * -1;
            }
        }
    }
    //circumference
        for(int i=0; i<w; i++){
            punkty[i][0].x = rand()%obwodzik;
            punkty[i][0].y = rand()%obwodzik;
            if(rand()%2==0){
            punkty[i][0].x = punkty[i][0].x * -1;
            }
            if(rand()%2==0){
            punkty[i][0].y = punkty[i][0].y * -1;
            }
    }

        for(int i=0; i<w; i++){
            punkty[i][k-1].x = rand()%obwodzik;
            punkty[i][k-1].y = rand()%obwodzik;
            if(rand()%2==0){
            punkty[i][k-1].x = punkty[i][k-1].x * -1;
            }
            if(rand()%2==0){
            punkty[i][k-1].y = punkty[i][k-1].y * -1;
            }
    }


        for(int j=0; j<k; j++){
            punkty[0][j].x = rand()%obwodzik;
            punkty[0][j].y = rand()%obwodzik;
            if(rand()%2==0){
            punkty[0][j].x = punkty[0][j].x * -1;
            }
            if(rand()%2==0){
            punkty[0][j].y = punkty[0][j].y * -1;
            }
        }

        for(int j=0; j<k; j++){
            punkty[w-1][j].x = rand()%obwodzik;
            punkty[w-1][j].y = rand()%obwodzik;
            if(rand()%2==0){
            punkty[w-1][j].x = punkty[w-1][j].x * -1;
            }
            if(rand()%2==0){
            punkty[w-1][j].y = punkty[w-1][j].y * -1;
            }
        }
        liczba_zmian++; //liczba zmian w obu tablicach
    }



void drukuj(Punkt punkty[w][k]){

    //prints tab
    for(int i=0; i<w; i++){
        for(int j=0; j<k; j++){
            cout << punkty[i][j].x << ";" << punkty[i][j].y << "\t";
        }
        cout << endl;

}

cout << endl << "liczba zmian: " << liczba_zmian << endl;
}
void kolumny(Punkt punkty[w][k], int kolumna, int stala, int &liczba_zmian)
{
    srand(time(NULL));
     int suma_x=0;
     int liczba_x=0;

    for(int i=0; i<w; i++){
        for(int j=0; j<k; j++){
            if(j==kolumna && punkty[i][j].x > stala){
                suma_x = suma_x + punkty[i][j].x;
                liczba_x++;
            }
        }
        cout << endl;
    }
    for(int i=0; i<w; i++){
        for(int j=0; j<k; j++){
            if(j==kolumna){
                punkty[i][j].x = suma_x/liczba_x;
            }
        }
        cout << endl;
    }
    liczba_zmian++; //liczba zmian w obu tablicach
}

int main()
{
    Punkt A[w][k];
    Punkt B[w][k];
    const int G=5;

    wypelnij(A, 20, 10);
    wypelnij(B, 10, 20);
    drukuj(A);
    drukuj(B);
    kolumny(A, 1, 0, liczba_zmian);
    kolumny(B, 3, G, liczba_zmian);
    drukuj(A);
    drukuj(B);
    return 0;
}
