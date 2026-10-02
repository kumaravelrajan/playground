#include <iostream>

using namespace std;

int add (int a , int b)
{
    return a + b;
}

float add (float a, float b)
{
    return a + b;
}

int main () {

    int inta = 4, intb = 5;

    float floata = 4.5, floatb = 5.5; 

    cout << "add() with int values = " << add(inta, intb) << endl;

    cout << "add() with float values = " << add(floata, floatb) << endl;

	return 0;

}