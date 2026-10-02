#include <iostream>

using namespace std;

int main () {

    char my_name_quoted[] = {'k', 'u', 'm', 'a', 'r', '\0'};

    /* When string is declared using above syntax, we manually have to add null character at the end. */

    cout << "Printing values from my_name_quoted with condition: my_name_quoted[i] != \\0 --> ";

    for (int i = 0; my_name_quoted[i] != '\0'; i++){
        cout << my_name_quoted[i];
    }

    cout << endl;

    /* The below loop utilizes the property that when a null character is encountered, it is treated as false in C++ and hence loop will be exited at the end of string. */

    cout << "Printing values from my_name_quoted with condition: my_name_quoted[i] --> ";

    for(int i = 0; my_name_quoted[i]; i++){
        cout << my_name_quoted[i];
    }

    cout << endl;

    /* The string defined using below syntax does not need us to manually input the null character in the end but we can still see that the null character is still present at the end by using a for loop. */

    char my_name_not_quoted[] = "kumar";

    cout << "Printing values from my_name_not_quoted with condition: my_name_not_quoted[i] --> ";

    for (int i = 0; my_name_not_quoted[i]; i++){
        cout << my_name_not_quoted[i];
    }

    cout << endl;

    /* Looping through a string with character pointers */

    cout << "Printing values from my_name_not_quoted by setting char* char_pointer = my_name_not_quoted AND having condition: *char_pointer --> ";

    for (char* char_pointer = my_name_not_quoted; *char_pointer ; char_pointer++)
    {
        cout << *char_pointer;
    }

    cout << endl;
    
    cout << "Using for each loop to print out string in my_name_not_quoted --> \n";

    /* Below, we get the output as follows: 
    
        Current char -> k
        Current char -> u
        Current char -> m
        Current char -> a
        Current char -> r
        Current char -> 

        The last empty line is trying to print out the null character present at the end of the string. 
    */

    for (char c : my_name_not_quoted){
        cout << "Current char -> " << c << endl;
    }

    cout << endl;

	return 0;

}