/*
1. From the file with the name given by the user, read the real data in rows
(can be negative, can be without dot) to the array A[n][n] (n - constant). If the data in
file will be too small, free places in table A should be filled with a value
constant x.
2. Print the table with lines with a fixed number of p places after the decimal point and a constant
width d columns.
3. Find the largest number on the main diagonal (or the first of several
largest) and write it in the whole row containing this number.
4. Find the smallest number under the main diagonal (or the first one of several
smallest) and write it in the whole column containing this number.
5. Print the table again (in the format as in point 2).
6. Finally, save the entire table in lines (in the format as in point 2) to a file named
"new.txt".
*/

#include <iostream>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include<algorithm>
#include<string>
#include <iomanip>

using namespace std;

const int n=5;
const int x=3;
const int p=3;
int col_width=4;
float biggest=1.175494e-38;
int verse;
float smallest=1.175494e38;
int col;

int main()
{
    fstream plik;
    float A[n][n];
    plik.open("dane_do_A.txt", ios::in);

    if(plik.good()==false){
        cout << "nie mo¿na otworzyæ pliku";
        exit(0);
    }

      for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            A[i][j] = x;
        }
        }


    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            plik >> A[i][j];
            }
            }

        //prints tab
          for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
            cout << setw(col_width) << setprecision(p) << A[i][j] << "\t";
            }
            cout << endl;
        }
	
	//najwieksza na glownej przekatnej
        for (int i = 0; i < n; i++){
            if(A[i][i] > biggest || A[i][i] == biggest){
                biggest = A[i][i];
                verse = i;
            }
        }

        for (int j = 0; j < n; j++){
            A[verse][j] = biggest;
            }

        cout << endl << endl;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
            cout << setw(col_width) << setprecision(p) << A[i][j] << "\t";
            }
            cout << endl;
        }
	
	//najmniejsza liczba pod glowna przekatna

        for (int i = 0; i < n-1; i++){
            if(A[i+1][i] < smallest || A[i+1][i] == smallest){
                smallest = A[i+1][i];
                col = i;
            }
        }

            for (int i = 0; i < n; i++){
            A[i][col] = smallest;
            }


    cout << endl << endl;


        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
            cout << setw(col_width) << setprecision(p) << A[i][j] << "\t";
            }
            cout << endl;
        }
	

	//zapis do nowego pliku
       fstream plik2;

        plik2.open("nowa.txt", ios::out);

    if(plik2.good()==false){
        cout << "plik nie istnieje";
        exit(0);
    }


        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
            plik2 << A[i][j] << "\t";
            }
            plik2 << endl;
        }

    plik.close();

    plik2.close();


    return 0;
}
