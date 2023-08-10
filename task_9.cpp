#include <iostream>
#include <time.h>
#include <string>

using namespace std;

struct SomeStruct{
    char letter;
    int digit;
};

const int G = 20;
const int n = 60;
int counter = 0;
char letters[] = "ABCDEFGHIJKMNOPRSTUWXYZ";
int operation;
int k;

void save_to_by_iteration(SomeStruct t[], int i, int m) {
    for(int i=0; i<m; i++){
        t[i].letter = letters[rand() % 23];
        t[i].digit = rand() % G;
    }
}

void save_to_recursion(SomeStruct t[], int i) {
    if(i < n){
        t[i].letter = letters[rand() % 23];
        t[i].digit = rand() % G;
        save_to_recursion(t, i+1);
    }
}

void print_tab(SomeStruct t[], int i, int x){
    for(int i=0; i<x; i++){
        if(i > x - 20 - 1){
        cout << t[i].letter << " | " << t[i].digit << " | index: " << i <<"\t";
        }
    }
}

int main()
{
    SomeStruct A[n];
    SomeStruct B[n];

    srand(time(NULL));

    // whole part (p0)

    cout << "Pick one of the operation (choose 1 2 or 3): ";
    cin >> operation;

    if(operation > 3 or operation < 1){
        cout << "You picked the wrong option, try again!";
        return 0;
    }

    if(operation == 1){
        save_to_by_iteration(A, 0, n);

        print_tab(A, 0, n);

        cout << endl << "A --> Limit here: about 26000~27000" << endl;

    }else if(operation == 2){
            save_to_recursion(B, 0);

            print_tab(B, 0, n);

        cout << endl << "B --> Limit in my case was approximately 23000~24000" << endl;
    }else{
        cout << "Enter k parameter to pass D table size (D[k]): ";
        cin >> k;

        SomeStruct *D;

        D = new SomeStruct[k];

        save_to_by_iteration(D, 0, k);

        print_tab(D, 0, k);

        delete [] D;

        cout << endl << "D --> Limit here: problems were in interval spanning 450~500 mln";
    }

    return 0;
}
