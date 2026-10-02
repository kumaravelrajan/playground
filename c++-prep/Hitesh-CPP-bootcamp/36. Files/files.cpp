#include <iostream>
#include <string>

using namespace std;

int main () {

    static const char * originalFile = "originalFile.txt";
    static const char * editedFile = "editedFile.txt";

    /* Open file for write */
    FILE *fp = fopen(originalFile, "w");

    /* Close file. Without closing file it would result in memory leak. */
    fclose(fp);

    /* Rename file */
    rename(originalFile, editedFile);

    /* Delete file */
    remove(editedFile);

	return 0;

}