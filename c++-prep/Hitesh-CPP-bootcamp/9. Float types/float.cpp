/* 
    Float data types - float, double, long double
*/

#include <iostream>

using namespace std;

int main () {

    printf("Float size is %ld bits.\n", sizeof(float));

    float my_float_value = 20.1;

    cout << "Value of my_float_value using cout which was assigned 20.1 = " << my_float_value << endl; /* Output 20.1 */

    printf("Value of my_float_value using printf which was assigned 20.1 = %f\n", my_float_value); /* Output 20.100000 */

    printf("Value of my_float_value using printf with 1 decimal point which was assigned 20.1 = %.1f\n", my_float_value); /* Output 20.1 */

	return 0;

}