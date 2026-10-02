#include <iostream>
#include <string>
#include <memory>

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

/* shared ptr unlike unique ptr can have shared references and can be copied. 

Only when ALL shared ptrs pointing to a memory location go out of scope is the memory location deleted. */

int main () {

    {
        shared_ptr<User> shared_pointer_to_user_object = make_shared<User>();
        {
            shared_ptr<User> copy_ptr = shared_pointer_to_user_object;
            {
                shared_ptr<User> copy_copy_ptr = copy_ptr;
            }
        }
    }

    /* The object is destroyed only here. */

    cout << "Outside scope\n";

	return 0;

}