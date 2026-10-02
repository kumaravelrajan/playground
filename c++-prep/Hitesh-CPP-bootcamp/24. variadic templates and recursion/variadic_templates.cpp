#include <iostream>
#include <string>

using namespace std;

/* Forms the base case of recursion. */
template <typename T>
void printFunc(T arg1){
    cout << "printFunc 1: " << arg1 << endl;
}

template <typename T, typename... variadic_args_type>
void printFunc(T arg1, variadic_args_type... variadic_args)
{
    cout << "printFunc 2: " << arg1 << endl;
    printFunc(variadic_args...);
}

template <typename T, typename... variadic_args_type>
void print_Func_With_Fold_Expression(T arg1, variadic_args_type... variadic_args)
{

    cout << "#####################################################\nACCESSING VARIADIC_ARGS WITH FOLD EXPRESSION\n";
    cout << "arg1 = " << arg1 << endl;

    cout << "Now displaying arguments in variadic_args: " << endl;

    ((cout << "Arg: " << variadic_args << endl), ...);
}

int main () {

    string myName = "Kumaravel";

    /* The call functions in the following manner. 
    
        Execution Flow for
        printFunc(1, 2, 1.1, 2.2, myName);

        printFunc(1, 2, 1.1, 2.2, myName);
        → matches printFunc(T, variadic_args...)
        → prints "printFunc 2: 1"
        → calls printFunc(2, 1.1, 2.2, myName)

        printFunc(2, 1.1, 2.2, myName)
        → prints "printFunc 2: 2"
        → calls printFunc(1.1, 2.2, myName)

        printFunc(1.1, 2.2, myName)
        → prints "printFunc 2: 1.1"
        → calls printFunc(2.2, myName)

        printFunc(2.2, myName)
        → prints "printFunc 2: 2.2"
        → calls printFunc(myName)

        printFunc(myName)
        → matches the single-argument version
        → prints "printFunc 1: Kumaravel"
    */

    cout << "#####################################################\nACCESSING VARIADIC_ARGS WITH RECURSION\n";

    printFunc(1, 2, 1.1, 2.2, myName); /* Use recursion to unpack variadic_args */

    print_Func_With_Fold_Expression(1, 2, 1.1, 2.2, myName); /* Uses fold expression to one shot print all variadic_args */

	return 0;

}