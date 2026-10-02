#include <iostream> /* Inbuilt header files take angular brackets. */
// #include "adder.h" /* User created header files take quotes. */

/* We have not included adder.h here. So template_intro.cpp has no idea where addme() function is. But recall that in adder.h we had to function overload addme() to cover different types. This can be made simpler by creating a single function using templates. */

template<typename T>

T addme(T a, T b){
    return a + b;
}

using namespace std;

int main () {

    cout << "Result of integer returning addme() = " << addme(5, 6) << endl;
    cout << "Result of float returning addme() = " << addme((float) 5.5,(float) 6.5) << endl;

	return 0;

}