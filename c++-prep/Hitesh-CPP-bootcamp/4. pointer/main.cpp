#include <iostream>

using namespace std;

int main() {

    int life = 4;

    int card = 40;

    cout << "Initial value of card is: " << card << endl;

    int card_duplicate = card;

    cout << "Initial value of card_duplicate is: " << card_duplicate << endl;

    int *my_p; /* Pointer declaration */

    my_p = &card; /* Store the memory address of card in my_p. my_p now points to card. */

    cout << "*my_p set to the value of 1000." << endl;

    *my_p = 1000; /* my_p itself contains the address of card. Dereferencing my_p gives the value of card. */

    cout << "New value of card : " << card << endl;

    cout << "New value of card_duplicate is: " << card_duplicate << endl;

    return 0;
}