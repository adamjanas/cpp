/*
Write a program that reads a sequence of integers until it reads an even number or
divisible by 3. Print the following information (taking all
loaded numbers):
• the smallest number loaded
• how many numbers were divisible by the constant D in this sequence
• how many times two negative numbers were read in succession.
NOTE: Write the program without using arrays, using a do-while loop.
*/

#include <iostream>
#include <windows.h>
#include <cstdlib>

using namespace std;

const int D = 11;
int number;
int count_negative=0;
int count_next_2_negative=0;
int count_divided_by_D =0;
int counter=0;
int indicator_min_number = INT_MAX;
int lowest;

int main()
{
    do
    {
        cout << "Insert number, if you choose even number or divided by 3, the program gonna interrupt: " << endl;
        cin >> number;

        if (number < 0) {
            count_negative++;
        } else{
            count_negative = 0;
        }
        if (number % D == 0){
            count_divided_by_D++;
        }
        if (count_negative == 2){
            count_next_2_negative++;
            count_negative = 1;
        }
        if (number < indicator_min_number){
            indicator_min_number = number;
        }

    }while(number % 3 != 0 && number % 2 != 0);

    cout << "Amount of numbers which are divided by our constant variable (D): " << count_divided_by_D << endl;
    cout << "Amount of consecutive 2 negative numbers: " << count_next_2_negative << endl;
    cout << "Lowest number: " << indicator_min_number << endl;

    return 0;
}
