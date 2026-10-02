# Data structures in C/C++ from freecodecamp

Video link - [here](https://youtu.be/B31LgI4Y4DQ?si=oa6n955r3aYjZmtW). 

# What is a data structure?
A data structure is a way to store and organize data in a computer, so that it can be used effectively. 

Data types are spoken about in two ways - 

1. As abstract data types (i.e. as mathematical / logical models) - 

    Eg: We can describe a List as a data structure that stores a given number of elements of any type, reads element by position and modify elements at a position. Do not have any implementation details. 

1. As a concrete implementation - 

    Eg: Most languages offer a concrete implementation of the lists described above. That is Arrays. 

# List 

## List as an abstract type

1. Static lists

    1. Static list should: 

        1. Store a given number of elements of a given data type. 

        1. Write/modify element at a position. 

        1. Read element at a position. 

    1. Static lists are implemented as arrays. These are fixed size, can write at a specific position and read elements at a specific position. 

1. Dynamic lists

    What if we wanted dynamic lists?

    1. Dynamic list should : 

        1. A list of size 0 designated as empty. 

        1. insert at any position. 

        1. Remove at any position. 

        1. Read/modify element at a position. 
    
    1. Implementation

        We can declare an array of large size to implement a dynamic array. But this comes with its problems. 

        1. Inserting at end (given array is not full) is easy - O(1). But inserting in the middle is harder. 

            Say, array has 5 element and we want to insert in pos 1. Then elements in position 1, 2, 3, 4 would have to be pushed back one position to empty the space in position 1. 

            Hence, Inserting takes O(n) with n being the array size. 

        1. Removing has the same problem as inserting. All elements following the removed element will have to be moved 1 position earlier. This means if dynamic lists are implemented as arrays removing also would have O(n).

        1. If the allocated space for the array gets over, then we cannot extend the existing array. Hence, a new array with an even larger size has to be created and the contents of the older array would have to be copied into the new array. This operation is once again costly. 

        1. Reading elements at a position is still O(1) though. This property is characteristic of arrays. 

## Limitations of using array to implemenet dynamic lists

We initially declare an array of size 4. Arrays are always contiguously allocated. This is why accessing elements in array is O(1) time. 

![](/data_structures_in_cpp/images/1_array_impl_of_dynamic_list.png)

But when we want to add new elements, we have a problem. We need to allocate a new array altogether because the memory just after our original array is blocked for variable x. Hence, memory manager allocates new larger array and copies contents of old array into new array. 

![](/data_structures_in_cpp/images/2_reallocating_array.png)

This array maybe larger but still suffers from the same problems as earlier. If too few elements present, memory wasted. If too much elements present a new larger array again has to be created and contents copied from old array to new array. 

This is where linked lists come in. 

## Linked lists

![](/data_structures_in_cpp/images/3_linked_list_intro.png)

Access takes O(n) because the element has to be traversed starting from head position. 

Insertion also takes O(n). Even though the actual insertion operation is quite a simple operation (unlike Arrays where there was creation of new larger array and copy of contents from old to new array involved) but still the position where we to make the insertion has to be traversed to by starting from the head position. This takes O(n). Hence, insertion also is O(n).

## Array vs Linked lists to implement dynamic lists

|Property|Array|Linked list|
|-|-|-|
|Accessing element|O(1)|O(n)|
|Inserting element| at beginning: O(n) | At beginning: O(1) |
|  | In the middle: O(n) | In the middle: O(n) |
|  | At the end when array NOT full: O(1) | At the end: O(n) |
|  | At the end when array full: O(n) | N/A |

The complexities for deletion are the same as insertion. 

## Implementing linked lists

[Click here](/data_structures_in_cpp/code/linked_list_implementation/1_linked_list_implementation.cpp)  to see implementation of linked lists in C++.

---

**Decided to stop this video midway and switch to the following video from Boot.dev. Reason being that the boot dev course was shorter and newer. If something from the above video needs to be learnt I will come back here.**

---

# Data structures and algorithms form Boot.dev

[Video Link click here](https://youtu.be/DMeD8trbj6A?si=I9h2cXmH2vmIg9jI)

# Math

1. Factorials (grow faster than) Exponentials (grow faster than) Linear.

# Big O Analysis

## Big-O is worst case analysis. 

![Big-O analysis](/data_structures_in_cpp/images/4_bigo.jpg)

Ordered by fastest to slowest speeds with O(1) being the fastest.

1. O(1) - constant
1. O(log n) - logarithmic
1. O(n) - linear
1. O(n^2) - Polynomial
1. O(2^n) - Exponential
1. O(n!) - factorial

