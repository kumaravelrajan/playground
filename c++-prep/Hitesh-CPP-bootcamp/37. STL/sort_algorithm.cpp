#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main () {

    float int_numbers[6] = {9,8,7,6,5,4};
    float float_numbers[6] = {9.8,8.7,7.6,6.5,5.4,4.3};

    /* int_numbers */

    cout << "Original int_numbers[6] array: " ;

    for(int n : int_numbers){
        cout << n << " ";
    }

    cout << endl;

    sort(int_numbers, int_numbers+6);

    cout << "Sorted int_numbers[6] array: " ;

    for(int n : int_numbers){
        cout << n << " ";
    }

    cout << endl;

    /* float_numbers */

    cout << "Original float_numbers[6] array: " ;

    for(float n : float_numbers){
        cout << n << " ";
    }

    cout << endl;

    /* Notice that the same sort() method is used here for float_numbers as for int_numbers. This is because sort() is a templated function included in STL.  */
    sort(float_numbers, float_numbers+6);

    cout << "Sorted float_numbers[6] array: " ;

    for(float n : float_numbers){
        cout << n << " ";
    }

    cout << endl;

	return 0;

}