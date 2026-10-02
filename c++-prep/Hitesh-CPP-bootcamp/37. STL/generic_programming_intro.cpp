#include <iostream>
#include <string>

using namespace std;

template <typename generic_type_1>
generic_type_1 getBigger(generic_type_1 a, generic_type_1 b){

    if(a > b){
        return a;
    } else if (b > a){
        return b;
    } else {
        return a;
    }

}

int main () {

    cout << "Bigger value out of 3 and 4: " << getBigger(3, 4) << endl;
    cout << "Bigger value out of 3.7 and 4.1: " << getBigger(3.7, 4.1) << endl;
    cout << "Bigger value out of 'a' and 'b' (compares ASCII values) : " << getBigger('a', 'b') << endl;

	return 0;

}