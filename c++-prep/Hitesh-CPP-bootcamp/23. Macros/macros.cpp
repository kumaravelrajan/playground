#include <iostream>
#include <string>

/* MACROS */

#define INT32_DATA_TYPE int32_t
#define console_log(text) cout << text << endl

using namespace std;

int main () {

    INT32_DATA_TYPE sampleint = 73;

    console_log(string("value of sampleint is : ") + to_string(sampleint));

	return 0;

}