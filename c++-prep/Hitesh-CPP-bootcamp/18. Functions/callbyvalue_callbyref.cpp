#include <iostream>

using namespace std;

void callByValue (int life)
{
    ++life;
}

void callByReference_1(int *life){
    ++(*life);
}

void callByReference_2(int &life){
    ++life;
}

int main () {

    /* Call by value */

    int life = 3;

    callByValue(life);

    cout <<"value of 'life' after callByValue(life) -> " << life << endl; /* Unchanged */

    /* Call by reference 1 */

    callByReference_1(&life);

    cout <<"value of 'life' after callByReference_1(&life) -> " << life << endl; /* Incremented by one to 4 */

    /* Call by reference 2 */

    callByReference_2(life);

    cout <<"value of 'life' after callByReference_2(life) -> " << life << endl; /* Incremented by one to 5 */

	return 0;

}