#include <iostream>
#include <string>
#include <memory>

using namespace std;

class B; 

class A{

    public:
    std::shared_ptr<B> ptrB;

    A(){
        cout << "Object A created\n";
    }

    ~A(){
        cout << "Object A destroyed.\n";
    }
};

class B{
    public: 
    std::weak_ptr<A> ptrA; /* MOST IMPORTANT PART */

    B(){
        cout << "Object B created.\n";
    }

    ~B(){
        cout << "Object B destroyed.\n";
    }
};

int main(){

    /* WEAK POINTERS SOLVING CYCLICAL REFERENCE ISSUE IN SHARED POINTERS -    
    
        If A and B both had shared_ptr for each other within them, this would increase heap_mem_block_A and heap_mem_block_B reference counts by 1 each. Remember, a mem block is deleted in heap ONLY IF its associated reference count is 0. But here in this code, even if ptr_to_objectA_in_heap and ptr_to_objectB_in_heap go out of scope at the end of main(), the heap_mem_block_A and heap_mem_block_B would still have reference count 1 (because they point to each other). This means these blocks will not be deleted and this causes memory leaks. 

        On the other hand, A has shared_ptr to B and B has weak_ptr to A. This means when ptr_to_objectA_in_heap and ptr_to_objectB_in_heap go out of scope at end of main(), the ref counts of heap_mem_block_A would be 0 and ref count of heap_mem_block_B would be 1. As soon as heap_mem_block_A is deleted, ref count of heap_mem_block_B would also be 0. Hence, this is also deleted. Therefore, there is no memory leak.     
    
    */


    shared_ptr<A> ptr_to_objectA_in_heap = make_shared<A>(); 
    shared_ptr<B> ptr_to_objectB_in_heap = make_shared<B>(); 

    ptr_to_objectA_in_heap->ptrB = ptr_to_objectB_in_heap;

    ptr_to_objectB_in_heap->ptrA = ptr_to_objectA_in_heap;    

    return 0;
}