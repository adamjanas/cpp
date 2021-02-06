
/*
Write a program that:
a. reads the subtitles until the subtitle ending with a dot is read and prints information if
the longest read string is longer than the shortest. The last one should not be taken into account
string (the one with a dot) ending the string. A while loop should be used.
b. then reads the integer k, forcing k to be positive and less than the constant g (with a loop
do-while).
c. then reads a string of k strings (using a for loop), then prints the total number of characters that are
numbers in all these inscriptions.
d. finally randomizes n capital letters (n – constant) to the Z[n] array, prints this array, replaces two
the last characters with the first two and prints the array again (all with a for loop).
*/

#include <iostream>
#include <string>
#include <typeinfo>
#include <time.h>
#include <algorithm>
using namespace std;

string label;
int shortest = INT_MAX;
int longest = 0;

int xd;
int k=0;
int const g = 11;

string some_text;
int count_digits;

int const n = 7;
string Z[n];
string letters = "ABCDEFGHIJKMNOPRSTUWZ";
string x,y;


int main()
{
    // first task

    while(label.back() != '.'){
    cout << "Enter a string: ";
    cin >> label;
    if (label.back() == '.') { break; }
    if (label.size() < shortest) { shortest = label.size(); }
    if (label.size() > longest) { longest = label.size(); }
    }

    cout << "Difference in length between longest and shortest string equals: " << longest - shortest << "\n";

    // second task

    do
    {
        cout << "Enter positive integer smaller than our constant G: ";
        cin >> xd;
        if (xd > 0 && xd < g){
            k = xd;
        } else{
            cout << "Our integer should be positive and smaller than G, try again." << "\n";
        }
    }while(xd <= 0 || xd >= g);

    cout << "Okay our variable k equals: " << k << "\n";

    // third task

    for(int i=0; i<k; i++){
        cout << "Enter " << i+1 << " string, (we gonna count digits in them): " << "\n";
        cin >> some_text;
        for(int i=0; i<some_text.size(); i++){
            if(isdigit(some_text[i])){
                    count_digits++;
            }
        }
    }

    cout << "In our strings were: " << count_digits << " digit/digits" << "\n";

    // fourth task

    srand(time(NULL));

    for(int i=0; i<n; i++){
        Z[i] = letters[rand()%letters.size()-1];
        cout << Z[i] << "\n";
    }

    swap(Z[0], Z[n-1]);
    swap(Z[1], Z[n-2]);

    for(int i=0; i<n; i++){
        cout << i + 1 << " element: " << Z[i] << "\n";
    }

    return 0;
}
