#include <iostream>

using namespace std;

int main () {

    int integer_array[4] = {1, 2, 3, 4};

    cout << "integer_array[0]: " << integer_array[0] << endl;

    cout << "integer_array: " << integer_array << endl; /* integer_array without any index is a pointer that points to the 0th position of the array. When we deref. this pointer (by doing *integer_array) we essentially get the value at integer_array[0]*/

    int another_array[4];

    another_array[0] = 9;
    another_array[1] = 19;

    cout << "Value of another_array[2] that has not been assigned yet: " << another_array[2] << endl; /* Unassigned integer array index values default to 0 */

    cout << "another_array[0]: " << another_array[0] << endl;

    *another_array = 1000; /* setting another_array[0] to 1000 */

    cout << "new another_array[0]: " << another_array[0] << endl;
    
    cout << "another_array[1]: " << another_array[1] <<endl;

    int *ap = another_array; /* Assigning pointer ap to point to another_array's start address.  */

    ap++; /* Increment ap means, ap now points to another_array[1] */

    *ap = 1000; /* another_array[1] now has the value 1000 */

    cout << "New another_array[1]: " << another_array[1] << endl;

    /* Checking if (another_array + 1) also has the same effect as increment ap and then printing *ap. */
    
    cout << "*(another_array + 1): " << *(another_array + 1) << endl;

	return 0;

}