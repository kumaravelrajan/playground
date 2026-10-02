#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main () {

    vector<int> int_vector = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "Contents of int_vector = ";

    for (int x : int_vector){
        cout << x << " ";
    }

    cout << endl;

    /* Using partition. All elements of int_vector that match the predicate will be pushed to the front the vector and all elements that DO NOT match the predicate will be pushed to the back of the vector. */

    partition(int_vector.begin(), int_vector.end(), [](int x){return (x%2 == 0);}); /* Push all even elements in int_vector to the front. */

    cout << "Contents of int_vector after applying partitions = ";

    for (int n : int_vector){
        cout << n << " ";
    }

    cout << endl;

    /* Stable_partition tries to maintain the same order in which the elements originally appear in the container. */

	return 0;

}