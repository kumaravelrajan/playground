#include <iostream>

using namespace std;

int main () {

    int six = 6; /* binary = 110 */
    int seven = 7; /* binary = 111 */

    int result_of_bitwise_and = six & seven; 
    
    cout << "6 & 7 = " << result_of_bitwise_and << endl;  /* Output is 6 */

    /* 
    
        1 1 0
     &  1 1 1
     ------------
        1 1 0    ----> 6
     ------------
    
    */

	return 0;

}