#include <iostream>
#include <string>

using namespace std;

class User{

    /* Default status of class is private, so no one can access the secret. */
    int _secret = 22; 

    public:
    string name = "default";
    
    void classMessage(){
        cout << "Class is great, " << name << endl;
    }

    /* We have two options :
    
        1. int & newSecret
        2. const int & newSecret

        const int & newSecret (Option 2) is needed because this enables us to pass temporary values or literals during function calls. Hence we can pass setSecret(333) and not face an error. const int & makes sure that we CANNOT modify the literal value using this newSecret reference. 

        int & newSecret on the other hand enables modifying the literal value which does not make much sense. Hence, this causes a compilation error. This option would be fine if we were passing variables during function call. Then, lvalue of this variable will be taken into the reference newSecret.
    */

    void setSecret(int & newSecret){
        cout << "Function called : void setSecret(int & newSecret)" << endl;
        _secret = newSecret;
    }

    void setSecret(const int & newSecret){
        cout << "Function called : void setSecret(const int & newSecret)" << endl;
        _secret = newSecret;
    }

    int getSecret(){
        return _secret;
    }
};

int main () {

    /* sam is called object of class User. */

    User sam; 

    sam.classMessage(); /* Class is great, default */
    sam.name = "Sam";
    sam.classMessage(); /* Class is great, Sam */

    cout << "Initial secret value : " << sam.getSecret() << endl;
    
    sam.setSecret(333); /* Calls void setSecret(const int & newSecret) */

    cout << "sam.setSecret(333); : " << sam.getSecret() << endl;
    
    int sample = 5000;
    sam.setSecret(sample); /* Calls void setSecret(int & newSecret) */

    cout << "Value should be 5000 : " << sam.getSecret() << endl;

	return 0;

}