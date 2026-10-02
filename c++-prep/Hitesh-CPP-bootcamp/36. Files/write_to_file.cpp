#include <iostream>
#include <string>

/* constexpr v/s From const
const only guarantees immutability after initialization; the object may be initialized at runtime.

constexpr guarantees both immutability and compile-time initialization, provided the requirements (such as literal types and constant expressions) are met. */
constexpr int maxbuffer = 1024;

using namespace std;

int main () {

    const char * filename = "some_text.txt";
    const char * fileContent = "lorem ipsum dolor sit amet ";

    /* Write file contents to file. */
    FILE *fh = fopen(filename, "w");

    for(int i = 0; i < 50; ++i){
        fputs(fileContent, fh);
    }

    fclose(fh);

    char buf[maxbuffer];

    /* File read */
    fh = fopen(filename, "r");

    while(fgets(buf, maxbuffer, fh)){
        fputs(buf, stdout);
    }

    fclose(fh);
    
	return 0;

}

