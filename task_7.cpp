/*
1. The table A[w][k] (w, k - constants) should be filled with random real numbers from the interval
<-r, r>, and the B[w][k] table - from the range <d, g> (r, d, g - constants).
2. Print table A in rows with an accuracy of 1 place after the decimal point, table B - z
accuracy of 2 places.
3. In table A, reverse the order of elements (i.e. replace the first with the last, the second with
penultimate, etc.) in rows with a negative sum of elements, and in array B do this
the same for rows where the sum of the elements is less than the read value.
4. Print both tables again.
5. Print information in which table more rows have been reversed (or maybe the same number).
*/

#include <iostream>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <iomanip>

using namespace std;

const int w = 5;
const int k = 6;

const int r = 100;
const int d = 200;
const int g = 300;
int xd[2];

float decimal;

void wypelnij_tab(float tab[w][k], string nazwa_tablicy)
{
    srand(time(NULL));

    if(nazwa_tablicy=="A"){
    for(int i=0; i<w; i++){
        for(int j=0; j<k; j++){
                decimal = rand()%100;
                tab[i][j] = rand()%r + (decimal / 100);
            if(rand()%2==0){
                 tab[i][j] = tab[i][j] * -1;
            }
        }
    }
    }else{  for(int i=0; i<w; i++){
                for(int j=0; j<k; j++){
                decimal = rand()%100;
                tab[i][j] = rand()%(g-d) + d + (decimal / 100);
            }
        }

    }
    for(int i=0; i<w; i++){
        for(int j=0; j<k; j++){
                if(nazwa_tablicy=="A"){
                  cout << '\a' << setprecision(3) << tab[i][j] << "\t";
                }else{
                    cout<< '\a' << setprecision(5) << tab[i][j] << "\t";
                   }
        }
        cout << endl;
    }
}


void zamiana(float tab[w][k], string nazwa_tablicy)
{
    srand(time(NULL));
    double suma=0;
    double sumy[w];
    double jakas_wartosc= 1650.8;
    int counter_A=0;
    int counter_B=0;


    if(nazwa_tablicy=="A"){
            for(int i=0; i<w; i++){
                for(int j=0; j<k; j++){
                   suma = suma + tab[i][j];
                }
                    sumy[i] = suma;
            }
            for(int i=0; i<w; i++){
                if(sumy[i] < 0){
                    counter_A++;
                    for (int low = 0, high = k - 1; low < high; low++, high--){
                            swap(tab[i][low], tab[i][high]);
                        }
                }
            }   xd[0] = counter_A;
                cout << "liczba odwroconych wierszy w A: " << counter_A << endl;
    }else{
            for(int i=0; i<w; i++){
                for(int j=0; j<k; j++){
                   suma = suma + tab[i][j];
                }
                    sumy[i] = suma;
            }
            for(int i=0; i<w; i++){
                if(sumy[i] < jakas_wartosc){
                    counter_B++;
                    for (int low = 0, high = k - 1; low < high; low++, high--){
                            swap(tab[i][low], tab[i][high]);
                        }
                }
            }
            xd[1] = counter_B;
            cout << "liczba odwroconych wiersz w B: " << counter_B << endl;
    }

    for(int i=0; i<w; i++){
        for(int j=0; j<k; j++){
                if(nazwa_tablicy=="A"){
                  cout << setprecision(3) << tab[i][j] << "\t";
                }else{
                    cout << setprecision(5) << tab[i][j] << "\t";
                   }
        }
        cout << endl;
    }
    if(xd[0] > -1 && xd[1] > -1){
    if(xd[0]>xd[1]){
        cout << "wiecej odwrocono w A" << endl;
    }else if(xd[0] == xd[1]){
        cout << "odwrocono taka sama ilosc wierszy" << endl;
    }else{
     cout << "wiecej odwrocono w B" << endl;
    }
    }
}



int main()
{
    float A[w][k];
    float B[w][k];

    wypelnij_tab(A, "A");
    cout << endl;
    wypelnij_tab(B, "B");
    cout << endl;
    zamiana(A, "A");
    cout << endl;
    zamiana(B, "B");

    return 0;
}
