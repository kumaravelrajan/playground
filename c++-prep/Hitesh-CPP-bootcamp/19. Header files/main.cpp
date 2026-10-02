#include <iostream> /* Inbuilt header files take angular brackets. */
#include "adder.h" /* User created header files take quotes. */

using namespace std;

int main () {

    cout << "Result of integer returning addme() = " << addme(5, 6) << endl;
    cout << "Result of float returning addme() = " << addme((float) 5.5,(float) 6.5) << endl;

	return 0;

}