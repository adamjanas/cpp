/*
a. Table A[w][k] (w, k - constants) filled with random two-digit integers
(positive or negative).
b. Print the array in rows with the set print width, padding
each row ends with the average value of all the numbers in that row,
printed with an accuracy of 2 decimal places.
c. Cyclically shift 1 place to the right the rows where this mean is greater
as to the modulus from the constant G, then print the table again.
d. For each column, print (below that column) how many numbers are divisible by it
constant D
e. Print the indexes of the columns that have the fewest numbers divisible by the constant D.
*/

#include <iostream>
#include <time.h>
#include <iomanip>
#include <time.h>
#include <cmath>

using namespace std;

int w=5;
int k=6;
int sum=0;

int main()
{

    int A[w][k];

    for(int i=0; i<w; i ++){
        for(int j=0; j<k; j ++){
            A[i][j] = (rand() % 90) + 10;
            if(rand() % 2 == 0){
                A[i][j] *= -1;
            }
        }
    }

    for(int i=0; i<w; i ++){
        for(int j=0; j<k ; j ++){
            cout << A[i][j] << "\t";
        }
        cout << endl;
        cout << endl;
    }

    for(int i=0; i<w; i++){
        for(int j=0; j<k; j++){
            cout <<  setw(4) << A[i][j] << "\t";

        }
        cout << endl;
        cout << endl;
    }

    cout << endl;

    cout << "okay, now lets add element average of values in accurately this verse at the end in every verse:  " << endl << endl;

    int sum=0;

    for(int i=0; i<w; i++){
        for(int j=0; j<k; j++){
            cout << A[i][j] << "\t";
            sum+=A[i][j];
        }
        cout << " | " << setprecision(2) << double(sum)/double(k) << "\t";
        sum=0;
        cout << endl;
        cout << endl;
    }

     cout << "now lets move our array 1 place towards right (periodically) where average of elements is bigger than constant G :  " << endl;

    const int G=8;

        for(int i=0; i<w; i++){
        for(int j=0; j<k; j++){
            sum+=A[i][j];
            if(abs(double(sum)/double(k)) > G){
            int schowek = A[i][k-1];
            for (int j = k-1; j > 0; j--)
            A[i][j] = A[i][j-1];
            A[i][0] = schowek;
            }

        }
        sum=0;
        cout << endl;
        cout << endl;
    }

        for(int i=0; i<w; i++){
        for(int j=0; j<k; j++){
            cout << A[i][j] << "\t";

        }
        cout << endl;
        cout << endl;
    }

    cout << "print how many digits is divided by constant D in columns: " << endl;

    const int D=3;
    int how_many=0;
    int lowest=INT_MAX;
    int column;
    int ileliczb[k];

    for(int j=0; j<k; j++){
        for(int i=0; i<w; i++){
            if(A[i][j] % D == 0){
                how_many++;
            }
            ileliczb[j] = how_many;
        }
        cout << j + 1 << " column" <<" | " << how_many << "\t";
        if(how_many < lowest){
            lowest = how_many;
        }
        how_many=0;
        cout << endl;
        cout << endl;
    }

    cout << "indexes of the columns with the smallest amount of digits divided by D: " << endl;

    for(int i=0; i<k; i++){
        if(lowest == ileliczb[i]){
           cout << "index: " << i << endl;
        }
    }
  return 0;
}
