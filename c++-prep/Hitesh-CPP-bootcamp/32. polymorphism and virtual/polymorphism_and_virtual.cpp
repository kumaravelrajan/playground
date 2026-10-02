#include <iostream>
#include <string>

using namespace std;

class One{
    public: 
    virtual void intro(){
        cout <<"Inside One\n";
    }

};

class Two: public One{
    public:
    void intro(){
        cout << "Inside Two\n";
    }

    void unique_method_in_two(){
        cout << "Unique function in two\n";
    }

};

class Three: public One{
    public:
    void intro(){
        cout << "Inside Three\n";
    }

    void unique_method_in_three(){
        cout << "Unique method in three.\n";
    }

};

int main () {

    One one;
    Two two;
    Three three;

    one.intro(); /* inside one */
    two.intro(); /* inside two */
    three.intro(); /* inside three */

    /* ################################################################### */

    cout << "###################################################\n";

    One *newOne;
    Two newTwo;
    Three newThree;

    newOne = &newTwo;

    newOne->intro(); /* Without virtual keyword prints - inside one. With virtual keyword prints - inside two. */

    newOne = &newThree;

    newOne->intro(); /* Without virtual keyword prints - inside one. With virtual keyword prints - inside three. */

    /* ####################################################################################### */

    /* NOTE: newOne can ONLY call methods present in One overridden in Two or Three. newOne pointer when pointing to a Two object or Three object CANNOT call a method unique to Two or Three. */

    /* newOne->unique_method_in_three(); --> NOT OK. */


	return 0;

}