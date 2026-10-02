#include <iostream>
#include <string>

using namespace std;

int main () {

    /* Not executed because no way to call this function. */
    [](){
        cout << "Lambda function 1 with simple cout\n"; 
    };

    /* Not executed because no way to call this function. */
    [](){
        cout << "Lambda function 2 returning 100\n";
        return 100;
    };

    auto sam = [](auto num1, auto num2){
        return num1 + num2;
    };

    cout << "Type of sam variable that contains the lambda function is : " << typeid(sam).name() << endl; /* The output of typeid(sam).name() for the lambda in your code will not be a friendly function type, but rather a compiler-specific, unique, unnamed class type created for that lambda expression. */

    cout << "Sum of 3 and 4 is : " << sam(3, 4) << endl;

    cout << "Sum of 3.5 and 4.7 is : " << sam(3.5, 4.7) << endl;

	return 0;
}