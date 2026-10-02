#include <iostream>
#include <string>

using namespace std;

class User{
    int _secret = 22;

    public:

    /* GETTERS */

        /* A constant reference is returned. The returned reference is an alias to the internal private _secret variable. Changing the alias also changes the value of _secret. */
        const int& getSecret_constRef(){
            return _secret;
        }

        /* Returns a const pointer. i.e. The returned pointer CANNOT be used to modify the value of _secret member variable. But the returned pointer itself can be reassigned and set to nullptr for example.  */
        const int* getSecret_Normal_Pointer_constInt(){
            return &_secret;
        }

        int getSecret(){
            return _secret;
        }

        int getSecret_constMethod() const{
            return _secret;
        }

    /* SETTERS */

        // NOT OK: because this is const-qualified member and this means that it CANNOT modify a member variable. But modifying a non-member variable works just fine like sample. 
        /* void setSecret(int newSecret) const{
            int sample = 0;
            sample = 4; // Works just fine
            _secret = newSecret; // Not OK.
        } */
};

int main () {

    User u;

    /* Understanding getSecret_constRef() */

        const int local_const_var = u.getSecret_constRef(); /* OK. local_const_var not a ref of _secret. Instead local_const_var is independent variable that has same value as _secret. */

        int local_var = u.getSecret_constRef(); /* OK. local_var again not a reference of _secret. Instead, local_var is independent variable that has same value as _secret. */

        const int& local_const_ref = u.getSecret_constRef(); /* OK. local_const_ref is constant integer reference. This is an actual reference of _secret. But const keyword means local_const_ref cannot change its value and in turn cannot change value of _secret. */

        // int& local_non_const_ref = u.getSecret_constRef(); // NOT OK. This is trying to get an actual reference to _secret BUT make the reference local_non_const_ref modifiable. This betrays the return type of getSecret_constRef() which is "const int&". Hence, this causes compilation error. 





    /* Understanding getSecret_Normal_Pointer_constInt */

        /* #################################   POINTER TYPES   #############################################
            Type                  |  Pointer value (address)  |  Value pointed to                 
            ----------------------+---------------------------+-----------------------------------
            int *ptr              |  Can be changed           |  Can be changed                   
            const int *ptr        |  Can be changed           |  Cannot be changed through pointer
            int *const ptr        |  Cannot be changed        |  Can be changed                   
            const int *const ptr  |  Cannot be changed        |  Cannot be changed through pointer
        #################################   POINTER TYPES   ############################################# */

        // 1
            const int* local_normal_ptr_const_int = u.getSecret_Normal_Pointer_constInt(); /* OK. local_normal_ptr_const_int can only dereference and read value in _secret. But it cannot modify value of _secret. */

            cout << "*local_normal_ptr_const_int" << *local_normal_ptr_const_int;

            // *local_normal_ptr_const_int = 45; --> Causes error.

            local_normal_ptr_const_int = nullptr;

        // 2
            const int *const local_const_ptr_const_int = u.getSecret_Normal_Pointer_constInt(); /* OK. local_const_ptr_const_int cannot change the address it points to AND cannot change value in the address being pointed to. */

            // local_const_ptr_const_int = nullptr; --> Causes error. The pointer CANNOT be reassigned to point to a different address. 

        // 3
            // int* local_normal_ptr_normal_int = u.getSecret_Normal_Pointer_constInt();  --> NOT OK. Because, if compiler error was not raised, this would mean local_normal_ptr_normal_int can easily be dereferenced and change value of _secret. This is however explicitly forbidden by return type of getSecret_Normal_Pointer_constInt() i.e. "const int*"

        // 4
            // int *const local_const_ptr_normal_int = u.getSecret_Normal_Pointer_constInt(); --> NOT OK. Because, here local_const_ptr_normal_int cannot be reassigned to point to a new address, but the value at the address being pointed to can be changed. This is not what getSecret_Normal_Pointer_constInt() lets us do.

    



    /* Understanding const class objects */

    const User const_user_obj;

    /* OK. Works fine.  
    
        - const objects promise that the internal state (value of member variables) will remain the unchanged throughout the scope of the object. It can only be assigned values at the time of object creation using a constructor for example.

        - const objects can ONLY call const member functions. const member functions CANNOT modify member variables. const member functions can ONLY call other const member functions. 

        - non-const objects can also call const-member functions.
    */
    const_user_obj.getSecret_constMethod(); 

    // const_user_obj.getSecret(); --> NOT OK.

    u.getSecret(); /* OK */

    u.getSecret_constMethod(); /* OK */
    
	return 0;

}