#include <iostream>

using namespace std;

int main () {

    int score = 200;
    int *mypointer = &score; /* mypointer stores memory address of score variable. */

    cout << "Score = " << score << endl; /* Prints 200 */
    cout << "mypointer = " << mypointer << endl; /* Prints address of score variable. */

    int &another_score = score; /* A REFERENCE VARIABLE another_score is declared as an alias (another name) for the variable score. References must be initialized when declared and cannot be changed to alias another variable later. */

    another_score = 800; /* Assigning 800 to another_score actually changes the value of score as well, because another_score is just another name for score. */

    cout << "Score = " << score << endl; /* 800 */
    cout << "mypointer = " << mypointer << endl; /* Same address as earlier is stored in mypointer. */

    return 0;
}