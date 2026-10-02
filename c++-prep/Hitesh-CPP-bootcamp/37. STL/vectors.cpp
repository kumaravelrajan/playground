#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main () {

    vector<int> int_vector; 
    vector<string> string_vector = {"apple", "orange", "tiger", "lion"};

    int_vector.push_back(1);
    int_vector.push_back(2);
    int_vector.push_back(3);
    int_vector.push_back(4);
    int_vector.push_back(5);

    for(int i = 6; i < 10; ++i){
        int_vector.push_back(i);
    }

    cout << "int_vector.size() = " << int_vector.size() << endl;
    cout << "int_vector.capacity() = " << int_vector.capacity() << endl;
    cout << "int_vector.max_size() = " << int_vector.max_size() << endl;
    cout << "int_vector.empty() = " << int_vector.empty() << endl;

    cout << "int_vector = ";

    for(int num : int_vector){
        cout << num << " ";
    }

    cout << endl;

    /* Alternative 1 */

    cout << "int_vector = ";

    for(auto i = int_vector.begin(); i != int_vector.end(); ++i){
        cout << *i << " ";
    }

    cout << endl;

    /* Alternative 2 */

    cout << "int_vector = ";

    for(auto i = begin(int_vector); i != end(int_vector); ++i){
        cout << *i << " ";
    }

    cout << endl;

	return 0;

}