#include <iostream>
#include <string>

using namespace std;

class User{

    /* Default status of class is private, so no one can access the secret. */
    int _secret = 22; 

    public:
    string name = "default";
    
    /* Example of separating class method declaration and definition. */
    void classMessage();

    /* 
        SETTERS
    
        We have two options :
    
        1. int & newSecret

            int &newSecret means that newSecret is a non-const reference to the value passed in during call of setSecret(). This means if during calling I say setSecret(333) then int& newSecret in the defn. says that newSecret will be an alias of 333 AND it can also modify it. But how can you modify a literal? That makes no sense. Hence, this causes a compiler error. 

            However, using this format, we can safely pass in variables during calls to setSecret(). 

        2. const int & newSecret

            const int& newSecret means that newSecret is a constant reference to whatever is passed in during call of setSecret(). This means, newSecret CANNOT change the value it gets. This is why literals like setSecret(333) works here. We cannot change literals like 333. 

    */
    void setSecret(int & newSecret){
        cout << "Function called : void setSecret(int & newSecret)" << endl;
        _secret = newSecret;
    }

    void setSecret(const int & newSecret){
        cout << "Function called : void setSecret(const int & newSecret)" << endl;
        _secret = newSecret;
    }

    /* GETTERS */

    /* Meaning of const modifier in different positions in the member method definition
        1. int getSecret() const
            The const after the parameter list means this is a const-qualified member function.
            It promises not to modify any member variables (unless they're marked mutable) and can only call other const member functions.
            Used for methods that should not change the internal state of the object.

        2. const int getSecret()
            The const before the return type means the returned value is const.
            For built-in types like int, this has no practical effect—the caller gets a copy and cannot modify the original anyway.
            More useful for returning references or pointers.
        
        3. int const getSecret()
            This is identical to const int getSecret(); in C++, int const and const int are the same.
            Again, for built-in types, returning a const value is not meaningful.

        4. const int& getSecret(){return _secret}
            A constant reference is returned. The returned reference is an alias to the internal private _secret variable. Changing the alias also changes the value of _secret.

            Eg - 
            void main(){
                const int local_const_var = u.getSecret(); //OK. This is a copy of _secret. NOT a reference to _secret itself. 
                
                int local_non_const_var = u.getSecret(); // Also OK. But this is simply copying value of _secret into local_non_const_var. local_non_const_var is NOT a reference to _secret. Both are independent of each other. 

                const int& local_const_ref = u.getSecret(); // OK. Works fine. local_const_ref is reference to _secret. But since local_const_ref cannot be modified, hence _secret cannot be modified. 

                #################################   ERROR   #############################################
                int& local_non_const_ref = u.getSecret(); //NOT OK. Because we are attempting to store a const ref. to _secret into a non-const ref named local_non_const_ref. If successful this would enable changing value of _secret which completely defeats the purpose of our function const int& getSecret() function. 
                #################################   ERROR   #############################################
            }

        5. const int* getSecret(){return &_secret}
            Returns a const pointer. i.e. The returned pointer CANNOT be used to modify the value of _secret member variable. But the returned pointer itself can be reassigned and set to nullptr for example. 

            Eg - 
            void main(){

                const int* local_const_ptr = u.getSecret(); // OK. local_const_ptr can only dereference and read value in _secret. But it cannot modify value of _secret. 

                local_const_ptr = nullptr; // Also OK. We are not modifying _secret. Just reseating the local_const_ptr.

                const int *const const_value_const_address_ptr = u.getSecret(); // OK. Neither can value being pointed to be changed nor can the pointer be restated to point to a different location. 

                const const_value_const_address_ptr = nullptr; // NOT OK. The pointer CANNOT be reassigned to point to a different address. 

                #################################   ERROR   #############################################
                int* local_non_const_ptr = u.getSecret(); // NOT OK. If allowed this would mean that local_non_const_ptr  can change value of _secret by dereferencing that completely defeats the purpose of function definition having const int* getSecret().

                int *const const_address_pointer = u.getSecret(); NOT OK. This still says const_address_pointer can change the value at the address it is pointing to. What cannot be done is reassignment of const_address_pointer to a different address. But This will cause an error. 
                #################################   ERROR   #############################################





                #################################   POINTER TYPES   #############################################
                    Type                  |  Pointer value (address)  |  Value pointed to                 
                    ----------------------+---------------------------+-----------------------------------
                    int *ptr              |  Can be changed           |  Can be changed                   
                    const int *ptr        |  Can be changed           |  Cannot be changed through pointer
                    int *const ptr        |  Cannot be changed        |  Can be changed                   
                    const int *const ptr  |  Cannot be changed        |  Cannot be changed through pointer
                #################################   POINTER TYPES   #############################################
            }
    */

    int getSecret() const {
        return _secret;
    }
};


/* Writing classMessage() method of User class outside class definition */

void User::classMessage(){
    cout << "Class is great, " << name << endl;
}

int main () {

    /* sam is called object of class User. */

    User sam; 

    sam.classMessage(); /* Class is great, default */
    sam.name = "Sam";
    sam.classMessage(); /* Class is great, Sam */

    /* Notice that setting getSecret() to const does not affect sam object. This is because non-const class objects can safely call const methods. BUT const objects CANNOT call non-const methods (because these might modify internal state.) */

    cout << "Initial secret value : " << sam.getSecret() << endl;
    
    sam.setSecret(333); /* Calls void setSecret(const int & newSecret) */

    cout << "sam.setSecret(333); : " << sam.getSecret() << endl;
    
    int sample = 5000;
    sam.setSecret(sample); /* Calls void setSecret(int & newSecret) */

    cout << "Value should be 5000 : " << sam.getSecret() << endl;

    /* ##################################################################################################### */

    /* 
    Once we declare an object of a class as const we CANNOT call non-const member functions and cannot modify ANY non-mutable member variables. 
    
    The purpose of having a const class object is that the object remains unchanged throughout its scope and retains the values given to it at the time of declaration (maybe by using constructors.)

    const objects can ONLY call const member functions. const member functions also cannot modify any member variables and can ONLY call other const member functions. This ensures that the internal state of a const object remains unchanged. 

    */

    const User constObject;

    cout << "constObject.getSecret() : " << constObject.getSecret() << endl;

	return 0;

}