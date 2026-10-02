#include <iostream>
#include <string>

using namespace std;

class Man{
    string _name;
    int _age;

    Man(){}

    friend class Superman; /* Gives Superman class direct access to private members of base class Man. */

    protected:
    Man(const string& name_fromUser, const int& age_fromUser): _name(name_fromUser), _age(age_fromUser){}

    void run(){cout << "I can run";}

    void displaySuperPower(){ cout << "Man's super power is to sleep for 19 hours a day."; }

    public: 
    void sayName() const{
        cout << "My name is: " << _name << endl;
    }

    string getName(){return _name;}

    int getAge(){return _age;}

};

class Superman: public Man{
    bool flight;

    public: 
    Superman(string name): Man(name, 26){} 

    void run(){cout << "I am superman. I can run at light speed.\n"; } 

    /* Superman class is a friend of base class Man. Hence, we can directly access _name and _age which are private members in base class Man. */
    void sayNameAndAge(){
        cout << "name: " << _name << ";;; age: " << _age << endl;
    }
};

class Spiderman : public Man{
    bool webbing;

    public: 
    Spiderman(string name): Man(name, 19){};

    void run(){cout << "I am spiderman. I run normally.\n";}

    /* Spiderman class is NOT a friend class of base class Man. Hence, we CANNOT directly access _name and _age. Thus, we have to use getters from Man instead. */
    void sayNameAndAge(){
        cout << "name: " << getName() << ";;; age: " << getAge() << endl;
    }
};

int main () {

    Superman clark("Clark Kent");

    clark.sayName(); 

    clark.run(); 

    clark.sayNameAndAge();

    /* #################################################################################################### */

    Spiderman peter("Peter Parker");

    peter.sayName();

    peter.run();

    peter.sayNameAndAge();

	return 0;

}