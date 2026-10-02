#include <iostream>

using namespace std;

int main () {

    if(0){
        cout << "This code will never be executed." << endl;
    }

    if(NULL){
        cout << "This code also will never be executed." << endl;
    }

    if(11){
        cout << "This code also will always be executed." << endl;
        /* In fact any number other than 0 being present in the conditional means the true part of the conditional will always be executed. */
    }

    if(false){
        cout << "This code also will never be executed." << endl;
    }

    if(true){
        cout << "This code also will always be executed." << endl;
    }

    /* Ternary operators */

    int rating = 3;

    printf("You have been %s rated.\n", rating >= 4? "highly" : "badly");

	return 0;

}