#include <iostream>
#include <string>
#include <memory>

/* 1. Unique pointers - 

        - Memory gets free as soon as scope ends. No need for delete keyword to remove memory from heap AFTER the pointer was created using new keyword. 

        - Cannot be copied. There exist other pointers that can be copied. 

        - Tries to prevent memory leaks. Memory leaks usually happen in situations where ptrA and ptrB point to mem location. When delete keyword used on ptrA, the mem location is deleted. But ptrB still pointing to the mem location. 
        
        
*/


using namespace std;

class User{

    public: 

    User(){
        cout << "User object created\n";
    }

    ~User(){
        cout << "User object destroyed\n";
    }

    void testFunction(){
        cout << "This is a test function in class User\n";
    }
};

int main () {

    {
        /* Seperate scope starts */

        /* Method 1 of creating unique ptr (less preferred) */
        unique_ptr<User> unique_ptr_for_class_user(new User());

        /* Method 2 of creating unique ptr (more preferred method)*/

        unique_ptr<User> unique_ptr_for_class_user_2 = make_unique<User>();
        unique_ptr_for_class_user_2-> testFunction();

        // User* copy_ptr = unique_ptr_for_class_user_2; --> NOT OK because we used unique ptr
        // unique_ptr<User> copy_ptr_2 = unique_ptr_for_class_user_2; --> NOT OK because we used unique ptr

        /* Both user objects get destroyed automatically when execution exits the scope even though we did not call delete keyword explicitly. */
    }

    cout << "Outside the scope\n";

	return 0;

}