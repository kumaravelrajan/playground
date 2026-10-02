#include <iostream>

using namespace std;

int main () {

	int my_nums [] = {2, 4, 6, 8, 10};

	for (int i = 0; i < 5; i++){

		cout << "my_nums[" << i << "] = " << my_nums[i] << endl;
	}

	/* For range syntax */

	cout << "--------------- Below is the output from for-range ----------------" << endl;

	for(auto i : my_nums){
		cout << i << endl;
	}

	return 0;

}