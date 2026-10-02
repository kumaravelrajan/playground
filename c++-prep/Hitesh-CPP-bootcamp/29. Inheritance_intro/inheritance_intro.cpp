#include <iostream>
#include <string>

using namespace std;

/* 

           |  Base Class  |  Derived Class   |  Others        
-----------+--------------+------------------+----------------
Public     |  Accessible  |  Accessible      |  Accessible    
Protected  |  Accessible  |  Accessible      |  Not Accessible
Private    |  Accessible  |  Not Accessible  |  Not Accessible

*/

class Man{
    string _name;
    int _age;

    Man(){}

    protected:
    Man(const string& name_fromUser, const int& age_fromUser): _name(name_fromUser), _age(age_fromUser){}

    void run(){cout << "I can run";}

    void displaySuperPower(){ cout << "Man's super power is to sleep for 19 hours a day."; }

    public: 
    void sayName() const{
        cout << "My name is: " << _name << endl;
    }

};

class Superman: public Man{
    bool flight;

    public: 
    Superman(string name): Man(name, 26){} /* Constructor for Superman class that automatically invokes constructor for Man class. */

    void run(){cout << "I am superman. I can run at light speed.\n"; } /* Notice that we have a run() method in Man class as well. Here we are overriding the run() method. Hence, whenever a superman class object calls run() it will always call this overridden run() method. */
};

class Spiderman : public Man{
    bool webbing;

    public: 
    Spiderman(string name): Man(name, 19){};

    void run(){cout << "I am spiderman. I run normally.\n";}
};

int main () {

    Superman clark("Clark Kent");
    
    // clark.displaySuperPower(); --> NOT OK. displaySuperPower() is a protected method in Man class. This method can be accessed in the base class Man itself or inside the derived classes Superman and Spiderman but not outside these classes like we are trying to do here in main().

    clark.sayName(); /* sayName() is a public method from class Man. Hence, this can be accessed in the class Man, in derived class Superman and even outside like in main(). */

    clark.run(); /* The overridden run method in Superman class is run. */

    /* #################################################################################################### */

    Spiderman peter("Peter Parker");

    peter.sayName();

    peter.run();

	return 0;

}