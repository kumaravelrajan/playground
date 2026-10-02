#include <iostream>
#include <string>

using namespace std;

int main(){

    /* int type */
    int a = 10;
    int *p = &a;

    /* The pointer arithmetic increments the address (pointed to) by the size of the type pointed to, not by 1 byte. This is why p + 1 increments the pointer by 4 bytes when pointing to an integer on your system. This behavior is due to pointer arithmetic rules in C++: pointer values are incremented/decremented by multiples of the size of the pointed-to type (4 bytes), allowing iteration over arrays or contiguous memory blocks correctly.*/

    cout << "p = " << p << endl; /* 0x7fffffffdabc */
    cout << "Size of int  = " << sizeof(int) << endl; /* 4 */
    cout << "p + 1 = " << p + 1 << endl;  /* 0x7fffffffdac0 = 0x7fffffffdabc + 4 */

    /* char type */

    float f = 8.5;
    float* p_float = &f;

    cout << "p_float = " << p_float << endl; /* 0x7fffffffdab4 */
    cout << "size of float = " << sizeof(float) << endl; /* 4 */
    cout << "p_float + 1 = " << p_float + 1 << endl; /* 0x7fffffffdab8 */

    return 0;
}