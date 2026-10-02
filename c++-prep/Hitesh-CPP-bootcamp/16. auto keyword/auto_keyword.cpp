#include <iostream>
#include <string>

using namespace std;

string api_call_string(){
	return "Hey there, can you see my screen?";
}

int api_call_int(){
	return 1234;
}

/* Here, we prove that auto is not a separate data type and instead adapts to the data type it receives. Hence, C++ still remains a strongly type language. */

int main () {

	auto string_response = api_call_string();

	cout << "Response of api_call_string() -> " << string_response << endl;

	if(typeid(string_response) == typeid(string)){
		cout << "auto string_response is of type string and not a new data type \n";
	}

	auto int_response = api_call_int();

	cout << "Response of api_call_int() -> " << int_response << endl;

	if(typeid(int_response) == typeid(int)){

		cout << "auto int_response is of type int and not a new data type \n";

	}

	return 0;

}