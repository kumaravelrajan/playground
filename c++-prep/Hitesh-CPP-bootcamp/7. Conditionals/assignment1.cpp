#include <iostream>

using namespace std;

int main () {

    for(int rating = 1; rating < 6; rating++){
        cout << "The rating given by the customer is " << (rating == 1 ? 1 : rating == 2 ? 2 : rating == 3 ? 3 : rating == 4 ? 4 : rating == 5 ? 5 : 6) << endl;

    }

	return 0;

}