#include <iostream>

using namespace std;

int factorial(int number){
    if(number == 0){
        return 1;
    } else {
        return (number * factorial(number - 1));
    }
}

int main () {

    cout << "Factorial of 4 = " << factorial(4) << endl;

	return 0;

}