/* 
Write a function that for a list of goods starting at some address:
• removes at most two cheapest items from this list and passes their names through the parameters.
• moves the first item on the list to the place after the first encountered item with a name beginning with some character (if any) and returns (by return) the address of this encountered item.
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

    const int y = 21;
    string tab_of_names[y] = {"aa", "bb", "cc", "dd", "ee", "ff", "ee", "hh", "a1", "b1", "c1", "d1", "e1", "f1", "h1", "a2", "b2", "c2", "d2", "e2", "f2"};
    int list_size;
    string fst_cheap_name, snd_cheap_name;

void print_list(Towar *address)
{
  while (address != NULL)
  {
    cout << address->nazwa << " | " << address->cena << endl;
    address = address->nast;
  }
};


 Towar *TOWARY(Towar *address, char some_char, string &fst_cheap_name, string &snd_cheap_name)
 {

 Towar *aktualny = address;
 Towar *take_address = address;
 Towar *poprzedni = address;
 Towar *nowy = address;
 Towar *this_one = address;
 Towar *head = address;
 Towar *first = address;
 Towar *xd = address;

 int first_cheapest = INT_MAX;
 int second_cheapest = INT_MAX;

 // find cheapest price

  while (address != NULL)
    {

        if(address->cena < first_cheapest){
            first_cheapest = address->cena;
        }

        address=address->nast;
    }

  address = aktualny;

   cout << "Cheapest --> " << first_cheapest << endl;

// changing first element with the next element after element with the name that begins with specific char

int price_to_change_1;
string name_to_change_1;

price_to_change_1 = address->cena;
name_to_change_1 = address->nazwa;

address = aktualny;
nowy = new Towar;
nowy->cena = aktualny->cena;
nowy->nazwa = aktualny->nazwa;

 int take_first = 1;

  while (address != NULL)
  {
    if(address->nazwa[0] == some_char && take_first && address != aktualny){
        if(address->nast != NULL){
            poprzedni = address;
            this_one = poprzedni->nast;
            take_address = this_one;
            poprzedni->nast=nowy;
            nowy->nast = this_one;
            take_first -= 1;
        }
    }   poprzedni = address;
        address=address->nast;
    }

    address = aktualny->nast;
    delete xd;


    cout << "LIST AFTER SHIFTING: " << endl;

    print_list(address);



// handle removal of the element fst_cheapest

aktualny = head;
poprzedni= NULL;
int counter = 2;
while (aktualny != NULL)
  {
    if (aktualny->cena == first_cheapest and counter)
    {
      if (address == head){
        head = head->nast;
        }
      else{
        poprzedni->nast = aktualny->nast;
        this_one = aktualny;
        aktualny = aktualny->nast;
        if(counter==1){
            fst_cheap_name = this_one->nazwa;
        }else{
            snd_cheap_name = this_one->nazwa;
        }
        delete this_one;
      }
      counter -= 1;
    }else
    {
      poprzedni = aktualny;
      aktualny = aktualny->nast;
    }
}

 address = first->nast;

 if(address==NULL){
    cout << "We cannot print the list" << endl;
 }else{
    cout << "LIST AFTER REMOVAL AT LEAST TWO CHEAPEST COMMODITIES: " << endl;
        print_list(address);
    cout << "all done";
 }

 return take_address;
 }


int main()
{

  srand (time(NULL));

  list_size = rand() % 20 + 10;

  Towar *glowa, *aktualny;
  glowa = NULL;
  for (int i=0; i < list_size; i++)
  {
    aktualny = new Towar;
    aktualny->nazwa = tab_of_names[rand() % y];
    aktualny->cena = (rand() % 990) + 10;
    aktualny->nast=glowa;
    glowa=aktualny;
  };

  cout << "INITIAL LIST" << endl;

  print_list(glowa); // initial print

  const char specified_char = 'e';

  TOWARY(aktualny, specified_char, fst_cheap_name, snd_cheap_name);

  return 0;
}
