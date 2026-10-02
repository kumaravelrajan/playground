#include <iostream>

using namespace std;

int main () {

    int *array_pointer; 

    try
    {
        array_pointer = new int [100]; /* Allocates 100 spaces of memory. If allocation fails exception thrown. Hence, new statement is placed inside try-catch block. */
        cout << "Memory space allocated successfully";
    }
    catch(...) /* Catch-all catch segment that is triggered for any exception thrown in try. */
    {
        cout << "Failed to allocate memory";
    }
    
    delete [] array_pointer; /* delete never throws an exception even if we are trying to delete a pointer that was never allocated in the first place. 
    
    Note the syntax - delete [] array_pointer; 
    If array_pointer was just a memory address and not assigned to an array, we would have used 
    delete array_pointer;
    */

	return 0;

}