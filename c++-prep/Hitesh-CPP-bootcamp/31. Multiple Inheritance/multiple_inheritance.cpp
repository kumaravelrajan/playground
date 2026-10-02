#include <iostream>
#include <string>

using namespace std;

/* Base class 1 */
class Man{
    string _name;
    int _age;

    Man(){}

    friend class Superman; 

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

/* Base class 2 */
class Money{
    public: 
    void sayMoney(){cout << "Got 5k USD in my bank account\n"; }
};

/* Example of multiple inheritance */
class Superman: public Man, public Money{
    bool flight;

    public: 
    Superman(string name): Man(name, 26){} 

    void run(){cout << "I am superman. I can run at light speed.\n"; } 

    void sayNameAndAge(){
        cout << "name: " << _name << ";;; age: " << _age << endl;
    }
};

int main () {

    Superman clark("Clark Kent");

    /* Using methods from base class Man */

    clark.sayName(); 

    clark.run(); 

    clark.sayNameAndAge();

    /* Using  method from base class Money*/

    clark.sayMoney();

	return 0;

}