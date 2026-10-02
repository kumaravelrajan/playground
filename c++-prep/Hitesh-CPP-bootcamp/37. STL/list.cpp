#include <iostream>
#include <string>
#include <list>

using namespace std;

/* Vectors guarantee that memory locations are contiguous. But list makes no such promises.

    Singly linked lists have a different container. The lists used here are doubly linked lists. 

    A singly linked list contains nodes that hold data and a pointer to the next node, allowing only forward traversal, while a doubly linked list has nodes with data, a pointer to the next node, and an additional pointer to the previous node, enabling bidirectional traversal.

*/

int main () {

    list<int> myList; 

    for(int i = 3; i <= 10; ++i)
    {
        myList.push_back(i);
    }

    cout << "myList.front() = " << myList.front() << endl;

    cout << "myList.back() = " << myList.back() << endl;

    cout << "myList.pop_back();" << endl;

    myList.pop_back();

    cout << "New list : ";

    for (int n : myList){
        cout << n << " ";
    }

    cout << endl;

    cout << "myList.reverse();" << endl;

    myList.reverse();

    cout << "New list : ";

    for (int n : myList){
        cout << n << " ";
    }

    cout << endl;



	return 0;

}