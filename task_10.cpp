/*
1. Randomly select n given characters (goods, price) and create a one-way list from them in the order in which they are loaded. Place the sample names of the goods to be drawn in the name table (similarly to the characters to be drawn in the p0 program). Prices should be two- or three-digit.

2. Print the data of the records in the list along with their addresses, using the function that prints the list starting at some address, preceded by some header.

3. If the average price of the items on the list is lower than the constant C, add the item data read in from the keyboard to the first and last but one place of the list.

4. Reprint the list

5. Print the names of all items with the highest price and the names of all items beginning with the letter a or j.

6.Delete the created list using the function that deletes the list starting at some address.

7. Print the head of the list, i.e. the address of the beginning of the list after this operation.
*/


#include <iostream>
#include <time.h>
#include <string>

using namespace std;

    struct Towar{
        string nazwa;
        int cena;
        Towar *nast;
    };

    const int n = 15;
    const int y = 8;
    string tab_of_names[y] = {"aa", "bb", "cc", "dd", "ee", "ff", "gg", "hh"};
    const int C = 990;
    const int list_size = 10;
    int price_sum = 0;


void print_list(Towar *adres, string title)
{
  cout << title << endl;
  int index = 0;
  while (adres != NULL)
  {
    cout << adres->nazwa << " | " << adres->cena << " | " << adres << ", index ->  " << index << endl;
    index++;
    adres = adres->nast;
  }
};

void delete_list(Towar *element)
{
  if (element==NULL)
    return;
  cout << "Usuwanie --> " << element->nazwa << endl;
  delete_list(element->nast);
  delete element;
};


int main()
{

// 1

  Towar *glowa, *aktualny;
  glowa = NULL;
  for (int i=0; i < list_size; i++)
  {
    aktualny = new Towar;
    aktualny->nazwa = tab_of_names[rand() % y];
    aktualny->cena = (rand() % 990) + 10;
    price_sum = price_sum + aktualny->cena;
    aktualny->nast=glowa;
    glowa=aktualny;
  };

  // 2
  print_list(glowa, "initial list 1");

  // 3
  int new_price;
  aktualny=glowa;
  if(price_sum/list_size < C){
    while(glowa!=NULL)
        {
            if(glowa==aktualny){
                cout << "Enter first element: ";
                cin >> new_price;
                glowa->cena = new_price;
            }
            if(glowa->nast->nast==NULL){
                cout << "Enter penultimate element: ";
                cin >> new_price;
                glowa->cena = new_price;
                break;
            }
            glowa=glowa->nast;
        }

    }
    glowa = aktualny;

// 4

  print_list(glowa, "initial list 2");

// 5
  int biggest = glowa->cena;
  while (glowa != NULL)
    {
        if(glowa->cena > biggest){
            biggest = glowa->cena;
        }
        glowa=glowa->nast;
    }

glowa = aktualny;


  char first_letter;
  while (glowa != NULL)
    {
        if(glowa->cena == biggest){
            cout << "Name with the greatest price --> " << glowa->nazwa << endl;
        }

        first_letter = glowa->nazwa[0];

        if(first_letter == 97 || first_letter == 106){
            cout << "Name with 'a' or 'j' name's beginning --> " << glowa->nazwa << endl;
        }
        glowa=glowa->nast;
    }

    glowa = aktualny;
// 6

    delete_list(glowa);

    glowa = NULL;

// 7

    cout << "Adres glowy po operacji usuwania: " << glowa;

    return 0;
}
