#include <iostream>

using namespace std;

int main () {

    try
    {
        throw 40;
    }
    catch(int age)
    {
        cout << "Error caught successfully - " << age << endl;
    }
    

	return 0;

}