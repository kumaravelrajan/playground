#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main () {

    /* Binary search only works in sorted containers. Therefore, make sure to sort the container before running binary_search on it. */

    int int_numbers[6] = {9, 7, 8, 6, 5, 4};

    int number_to_search = 7;

    /* In unsorted array, number 7 NOT found by binary_search */
    if(binary_search(int_numbers, int_numbers+6, number_to_search)){
        cout << "Number " << number_to_search << " Found successfully.\n";
    } else {
        cout << "Number " << number_to_search << " NOT found.\n";
    }

    /* Sorting the array */

    sort(int_numbers, int_numbers+6);

    /* Found successfully now. */
    if(binary_search(int_numbers, int_numbers+6, number_to_search)){
        cout << "Number " << number_to_search << " Found successfully.\n";
    } else {
        cout << "Number " << number_to_search << " NOT found.\n";
    }

	return 0;

}