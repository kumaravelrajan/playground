#include <string>
#include <iostream>
#include <format>

using namespace std;

int main() {

    string first_name, last_name;
    
    cout << "Enter first name: ";

    getline(cin, first_name);

    cout << "Enter last name: ";

    getline(cin, last_name);

    cout << "Your full name is: " << first_name << " " << last_name << "\n";


    return 0;
}