#include <iostream>
#include <string>

using namespace std;

class Phone{

    string _os; 
    string _name;
    int _price;

    public: 
    
    /* Constructors */
    Phone(); /* Default constructor */
    Phone(const string& name_fromUser, const string& os_fromUser, const int& price_fromUser); /* Parametric constructor */
    Phone(const Phone& obj_to_copy_from); /* Copy constructor */

    /* Destructors */
    ~Phone();
    
    /* Getters */
    string getName(){return _name;}

    string getOS(){return _os;}

    int getPrice(){return _price;}
};

/* Default constructor */
Phone::Phone() : _os("Android_Default_value"), _name("Kumar_Phone_Default_value"), _price(0){
    cout << "Inside default constructor" << endl;
}; 

/* Parameter constructor */
Phone::Phone (const string& name_fromUser, const string& os_fromUser, const int& price_fromUser): _os(os_fromUser), _name(name_fromUser), _price(price_fromUser){
    cout << "Inside parameter constructor" << endl;
}

/* Copy constructor */
Phone::Phone (const Phone& source_object){
    cout << "Inside overwritten copy constructor" << endl;
    _name = source_object._name;
    _price = source_object._price;
    _os = source_object._os;
    
}

/* Destructor */

Phone::~Phone(){
    cout << _name + " destroyed." << endl;
}

int main () {

    /* Default constructor */
    Phone pixel1; 
    cout << "Pixel1:\nName: " << pixel1.getName() << "\nOS: " << pixel1.getOS() << "\nPrice: " << pixel1.getPrice() << endl;

    /* Parameter constructor */
    Phone pixel2("Pixel 2", "Android", 799);
    cout << "Pixel2:\nName: " << pixel2.getName() << "\nOS: " << pixel2.getOS() << "\nPrice: " << pixel2.getPrice() << endl;

    /* Copy constructor */
    Phone pixel3 = pixel2;    
    cout << "Pixel3:\nName: " << pixel3.getName() << "\nOS: " << pixel3.getOS() << "\nPrice: " << pixel3.getPrice() << endl;

	return 0;

}