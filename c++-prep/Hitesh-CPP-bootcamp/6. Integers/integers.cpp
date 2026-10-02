/* 

    Signed integer types    Unsigned integer types
    -----------------------------------------------
    short int                 unsigned short int
    int                       unsigned int
    long int                  unsigned long int
    long long int             unsigned long long int

*/

#include <iostream>
#include <cstdint>

using namespace std;

int main () {

    cout << "size of short int: " << sizeof(short int) * 8 << " bits" << endl;
    cout << "size of unsigned short int: " << sizeof(unsigned short int) * 8 << " bits" << endl;

    cout << "size of int: " << sizeof( int) * 8 << " bits" << endl;
    cout << "size of unsigned int: " << sizeof( unsigned int) * 8 << " bits" << endl;


    /* long int and long long int on linux/Mac are mostly 64 bits. But in windows systems they are different. long long int is double the size of long int. To avoid such discrepancies in data type sizes we use the types mentioned in <cstdint> which explicitly states the size of a given type*/
    cout << "size of long int: " << sizeof(long int) * 8 << " bits" << endl;
    cout << "size of unsigned long int: " << sizeof(unsigned long int) * 8 << " bits" << endl;

    cout << "size of long long int: " << sizeof(long long int) * 8 << " bits" << endl;
    cout << "size of unsigned long long int: " << sizeof(unsigned long long int) * 8 << " bits" << endl;


    cout << "------------------------CSTDINT types start here---------------------------" << endl;


    /* CSTDINT explicitly states how much space the data types contained within it need. */
    cout << "size of int8_t: " << sizeof(int8_t) * 8 << " bits" << endl;
    cout << "size of uint8_t: " << sizeof(uint8_t) * 8 << " bits" << endl;

    cout << "size of int16_t: " << sizeof(int16_t) * 8 << " bits" << endl;
    cout << "size of uint16_t: " << sizeof(uint16_t) * 8 << " bits" << endl;

    cout << "size of int32_t: " << sizeof(int32_t) * 8 << " bits" << endl;
    cout << "size of uint32_t: " << sizeof(uint32_t) * 8 << " bits" << endl;

    cout << "size of int64_t: " << sizeof(int64_t) * 8 << " bits" << endl;
    cout << "size of uint64_t: " << sizeof(uint64_t) * 8 << " bits" << endl;

    cout << "----------------------Converting Hex and Binary to Decimal----------------------\n";

    /* Converting Hex and binary to decimal. Decimal = 22; Hex = 0x16; Binary = 0b00010110 */

    printf("Decimal of 22 is : %d\n", 22);

    printf("Decimal of 0x16 is : %d\n", 0x16);

    printf("Decimal of 0b00010110 is : %d\n", 0b00010110);

    

	return 0;

}