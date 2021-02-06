/*
1. To the table of goods A[n][n] (n - constant) select records with fields (name of goods - type
char, price - int type) in such a way that:
• the names of the goods were in capital letters around the perimeter and on both diagonals of the board, and
in lowercase in the rest of the array.
• prices were in single or double digits.
2. Print the table in rows in the form of successive records, e.g. a10 R 7 w93…
3. Swap the cheapest goods lying above the second diagonal of the table with the most expensive
the commodity in the last three rows of this table.
4. Again, print the table in rows and save it in rows to the price.txt file, w
format as in p.2.
*/

#include <iostream>
#include <time.h>
#include <cstdlib>
#include <fstream>

using namespace std;

const int n=8;
char letters[] = "abcdefghijklmnopqrstuvwxyz";

struct Towar
{
    char name;
    int price;
};

int main()
{

    Towar towary[n][n];

    srand(time(NULL));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            towary[i][j].name = letters[rand() % 26];
            towary[i][j].price = rand()%100;
        }
    }

    //main diagonal
    for(int i=0; i<n; i++){
            towary[i][i].name = (rand()%(90-65))+65;
            towary[i][i].price = rand()%100;
    }

    int xd = n-1;

    //second diagonal
    for(int i=0; i<n; i++){
            towary[i][xd].name = (rand()%(90-65))+65;
            xd--;
    }

    //circumference
        for(int i=0; i<n; i++){
            towary[i][0].name = (rand()%(90-65))+65;
            towary[i][n-1].name = (rand()%(90-65))+65;
    }

        for(int j=0; j<n; j++){
            towary[0][j].name = (rand()%(90-65))+65;
            towary[n-1][j].name = (rand()%(90-65))+65;
    }

    //change 'cheapest' with 'the most expensive' etc.

    int cheapest=INT_MAX;
    int exp=INT_MIN;
    int index_chp, index_exp;

    int xdd=n-1;

	//najtanszy nad druga przekatna

        for(int i=0; i<n-1; i++){
            if(towary[i][xdd].price < cheapest){
                cheapest=towary[i][xdd].price;
                index_chp = i;
            }
            xdd--;
    }

    for(int i=n-3; i<n; i++){
            for(int j=0; j<n; j++){
            if(towary[i][j].price > exp){
                exp=towary[i][j].price;
                index_exp = i;
           }
        }
    }

    swap(towary[index_chp][index_chp+1], towary[index_exp][index_exp+1]);

    //prints struct table
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << towary[i][j].name;
            cout << towary[i][j].price << "\t";
        }
        cout << endl;
    }

    //save to ceny.txt

    fstream plik;

    plik.open("ceny.txt", ios::out);

    if(plik.good()==false){
        cout << "file was not implemented!";
        exit(0);
    }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
            plik << towary[i][j].name;
            plik << towary[i][j].price << "\t";
            }
            plik << endl;
        }

    plik.close();

    return 0;
}
