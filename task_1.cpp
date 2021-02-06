/*
Write a program that:
1. Prompts the user for a name, reads it, and prints a greeting using that
names.
2. Reads any two integers into int variables.
3. Prints the number of negative numbers read in.
4. Prints the result of dividing the smaller number by twice the larger number.
5. Prints information whether the smaller of the read numbers is single-digit or not
two digits or more digits.
*/

#include <iostream>

using namespace std;

string name, division_msg, digits_msg;

int number1, number2, negative_count = 0;

double division;

int main()
{
    cout << "Insert your name: ";
    cin >> name;

    cout << "Your name is " << name << endl;

    cout << "Enter first number: ";
    cin >> number1;

    cout << "Enter second number: ";
    cin >> number2;

    cout << "First number: " << number1 << endl << "Second number: " << number2 << endl;

    if (number1<0)
    {
        negative_count++;
    }
    if (number2 <0)
    {
        negative_count++;
    }

    cout << "Amount of negative numbers: " << negative_count << endl;

    if (number1>number2 && number1!=0)
    {
        division = double(number2)/(2*double(number1));
        cout << "Division equals: " << division << endl;
    }
    else if (number1<number2 && number2 != 0)
    {
        division = double(number1)/(2*double(number2));
        cout << "Division equals: " << division << endl;
    }
    else if (number1 == number2)
    {
        division_msg = "Numbers are equal, in that case we cant do our division. Try with different numbers.";
        cout << division_msg << endl;
    }
    else
    {
        division_msg = "We cant divide by 0!";
        cout << division_msg << endl;
    }

    if (number1 > number2)
    {
        if (number2<10 && number2>-10)
        {
            digits_msg = "Second number (lower one) is single-digit ";
            cout << digits_msg << endl;
        }
        else if (number2>10 && number2<100 || number2<-10 && number2>-100)
        {
            digits_msg = "Second number (lower one) is two-digit ";
            cout << digits_msg << endl;
        }
        else
        {
            digits_msg = "Second number (lower one) has more than two digits ";
            cout << digits_msg << endl;
        }
    }
    else if (number2 > number1)
    {
         if (number1<10 && number1>-10)
        {
            digits_msg = "First number (lower one) is single-digit ";
            cout << digits_msg << endl;
        }
        else if (number1>10 && number1<100 || number1<-10 && number1>-100)
        {
            digits_msg = "First number (lower one) is two-digit ";
            cout << digits_msg << endl;
        }
        else
        {
            digits_msg = "First number (lower one) has more than two digits ";
            cout << digits_msg << endl;
        }
    }
    else
    {
            digits_msg = "Numbers are equal, so we cannot check amount of digits in lower one.";
            cout << digits_msg << endl;
    }
    return 0;
}
