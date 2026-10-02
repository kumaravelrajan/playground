/* 
    1. Qualifiers
    
        1.1 Modifications qualifiers (allows or does not allow modification of values)

            a. const

            b. volatile - Used in multithreading contexts. Volatile variables can be edited by multiple threads. This is how data is passed between threads. 

            c. mutable - Makes things mutable.

        1.2  Life duration qualifiers (How long should a value be accessible?)

            a. static

            b. register - Suggests to compiler to put a value in CPU register. Compiler can also ignore this. 

            c. extern - External libraries can contain functionalities and be included in code when needed using linking process. 

*/

#include <iostream>

using namespace std;

/* Static variables retain their value between function calls, while non-static variables are re-initialized every time. */

int lifeUp(){
    static int life = 3;
    return life = life + 1;
}

int lifeUpPreIncrement(){
    static int life = 3;
    return ++life;
}

int lifeUpPostIncrement(){
    static int life = 3;
    return life++;
}

int main () {

    /* Executing lifeUp */

    cout << "Your starting game life using lifeUp() is: " << lifeUp() << endl;

    cout << "Your updated game life using lifeUp() is: " << lifeUp() << endl;

    cout << "Your updated game life using lifeUp() is: " << lifeUp() << endl; /* Output is 4, 5, 6; Without static keyword output would be 4, 4, 4 */

    /* Executing lifeUpPreIncrement */

    cout << "Your starting game life using lifeUpPreIncrement() is: " << lifeUpPreIncrement() << endl;

    cout << "Your updated game life using lifeUpPreIncrement() is: " << lifeUpPreIncrement() << endl;

    cout << "Your updated game life using lifeUpPreIncrement() is: " << lifeUpPreIncrement() << endl; /* Output is 4, 5, 6 because increment happens BEFORE value is returned. */

    /* Executing lifeUpPostIncrement */

    cout << "Your starting game life using lifeUpPostIncrement() is: " << lifeUpPostIncrement() << endl;

    cout << "Your updated game life using lifeUpPostIncrement() is: " << lifeUpPostIncrement() << endl;

    cout << "Your updated game life using lifeUpPostIncrement() is: " << lifeUpPostIncrement() << endl; /* Output is 3, 4, 5 because first value is returned and AFTER that value is incremented. */

    

	return 0;

}