#include <iostream>

using namespace std;

struct User {

    const int id; 
    int age; 

    /* Default constructor */

    User() : id(001), age(22){}

};

int main () {

    /* Stack memory */

    int score = 100;
    cout << "stack score = " << score << endl;

    User stack_mike;

    cout << "stack_mike.id = " << stack_mike.id << endl;
    cout << "stack_mike.age = " << stack_mike.age << endl;

    cout <<"*****************************\n";


    /* Heap memory */

    int* heap_score = new int;
    *heap_score = 200;

    cout << "heap_score = " << *heap_score << endl;

    /* Always remember to delete heap allocated memory. */
    delete heap_score;

    heap_score = nullptr;

    /* Trying to access heap_score after its deletion. */

    cout << "Trying to access heap_score after its deletion : " << *heap_score << endl; /* Gives garbage value but does not raise error. */


    User* heap_mike = new User();

    cout << "heap_mike->id = " << heap_mike->id << endl;
    cout << "heap_mike->age = " << heap_mike->age << endl;

    delete heap_mike;

	return 0;

}