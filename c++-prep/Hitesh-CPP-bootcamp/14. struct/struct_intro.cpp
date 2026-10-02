#include <iostream>

using namespace std;

struct User {
    const int uId; 
    const char *name; 
    const char *email;
    int course_count;
};

int main () {

    User mickey = {001, "mickey", "mickey@cartoon.com", 2};
    User donald = {002, "donald", "donald@cartoon.com", 3};

    /* Changing donald's member variables */

    cout << "Donald old course count: " << donald.course_count << endl;
    cout << "Donald old email ID: " << donald.email << endl;

    donald.course_count = 4;

    donald.email = "donald@donald.com"; /* Note that course_count is simple int. Hence, this can be changed. However, email is const char *. How are we able to change the email then? This is because const char * email means that we CANNOT change the address the email pointer points to. BUT we can change the contents of the memory pointed to by email pointer. Hence, we can change the email. */

    cout << "Donald new course count: " << donald.course_count << endl;
    cout << "Donald new email ID: " << donald.email << endl;
    
    /* Even entire structs can have pointers. */
    User * donald_pointer = &donald; 

    /* Accessing member variables of donald using donald_pointer.*/

    donald_pointer->course_count = 1000;

    cout << "Donald course count after donald_pointer->course_count = 1000; : " << donald.course_count << endl;

    /* The arrow syntax is nothing but dereferencing donald_pointer to get the struct and then accessing course_content member variable. */

    (*donald_pointer).course_count = 50;

    cout << "Donald course count after (*donald_pointer).course_count = 50; : " << donald.course_count << endl;





	return 0;

}