/* This code explains why pointer variables need to be strongly typed. They may often be mistakenly seen as just storing addresses and hence maybe a char* pointer could be seen as capable of storing an int value. But this is not the case. */

#include <iostream>
#include <string>

using namespace std;

int main(){

	/* 1025 in binary = 00000000 00000000 00000100 00000001 */
	int a = 1025;
	
	/* 32 bit int pointer */
	int *p_int; 
	p_int = &a;

	cout << "Address of p_int = " << p_int << "; Value *p_int = " << *p_int << endl; /* 0x7fffffffdaa4; 1025 */

	cout << "Size of int = " << sizeof(int) << endl; /* 4 */

	cout << "Address of p_int + 1 = " << p_int + 1 << "; Value *(p_int + 1) = " << *(p_int + 1) << endl; /* 0x7fffffffdaa8; -9564 (junk) */

	// #############################################################################################

	/* char pointer */

	// char* p_char = p_int;  --> Gives error. Thus, typecasting required. 
	
	// #############################################################################################

	/* 
		static_cast does not allow direct casting between pointers to unrelated types such as int* to char*. This conversion is ill-formed and forbidden by static_cast rules since int and char are unrelated fundamental types, and there is no inheritance or standard conversion that static_cast can apply here.
		
		The C++ standard restricts static_cast to conversions that maintain type safety, such as casting up and down within class hierarchies or converting to/from void*. Pointer conversions between unrelated types, like int* to char*, require reinterpret_cast, which performs a low-level cast without safety checks and directly converts the pointer bit pattern.

	*/
	char* p_char = reinterpret_cast<char*>(p_int);

	// #############################################################################################

	/*
		The following does not work. 
		
		The reason you do not see the address in your cout statements with a char* pointer like p_char is due to how operator<< is overloaded for char* in C++. When you output a char*, cout treats it as a C-style string and prints the characters starting at the pointer's address until it encounters a null character ('\0'), instead of printing the pointer's actual memory address. 

		p_char outputs the string starting at that address.

		*p_char outputs the single character the pointer is pointing to.

		p_char + 1 outputs the string starting from the next character.

		*(p_char + 1) outputs the next single character.

		If you want to print the actual pointer address instead of the string, you can cast the pointer to void*:
	
	*/

	/* cout << "Address p_char = " << p_char << "; Value *p_char = " << *p_char;

	cout << "Size of char = " << sizeof(char);

	cout << "Address p_char + 1 = " << p_char + 1 << "; Value *(p_char + 1) = " << *(p_char + 1); */

	// #############################################################################################

	/* Casting the above code to void* to get pointer address and to int to get char value. */

	cout << "Address p_char = " << static_cast<void*>(p_char) << "; Value *p_char = " << static_cast<int>(*p_char) << endl; /* 0x7fffffffdaa4; 1 */

	cout << "Size of char = " << sizeof(char) << endl; /* 1 */

	cout << "Address p_char + 1 = " << static_cast<void*>(p_char + 1) << "; Value *(p_char + 1) = " << static_cast<int>(*(p_char + 1)) << endl; /* 0x7fffffffdaa5; 4 */

	/* 
		CLINCHER:
	
		1025 in binary = 00000000 00000000 00000100 00000001

		p_char initially points to least significant 8 bits. Hence we get the value 1. 

		p_char+1 moves to the next 8 bits. Hence, we get the value 4. 

	*/

	// ######################################################################################################

	/* void* type */
	
	void* p_void = p_int; /* Notice, no casting required here. */

	cout << "Address p_void = " << p_void << endl; /* 0x7fffffffdaa4 */

	// cout << "Value p_void = " << *p_void << endl; --> Not allowed.
	
	return 0;
}

/* TODO:
	1. Add code for next part in video where void* pointer is shown. 
*/