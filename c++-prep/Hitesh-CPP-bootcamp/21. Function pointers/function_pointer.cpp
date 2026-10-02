#include <iostream>

using namespace std;

void Interesting(){
    cout << "I am interesting" << endl;
}

int main () {

    /* Function pointer has unique syntax */

    void (*pointerToInteresting)() = Interesting;

    /* Ways to invoke function using function pointer. */

    pointerToInteresting();

    (*pointerToInteresting)();

	return 0;

}