Video Link - [Click here](https://youtu.be/zuegQmMdy8M?si=rtJyKhy0SmlCbt_r)

# Why are pointer variables strongly typed when all they do is store addresses?

![](/pointers_in_cpp/images/1_generic_ptr_type_vs_strongly_typed_ptr.png)

Because pointers are not just used to store addresses. They are also dereferenced to get the value being pointed to and modify the value. 

In the image we can see that ```int a``` made up of four bytes has the value 1025 stored in binary. The left most bit (MSB) acts as the sign bit. 

Now, pointer p points to ```int a```. If we print *p this would mean we want the value of a. Because p is integer pointer, the system knows to look for a 4 byte value to get the stored value correctly. 

If p had been a char*, then the system would have only looked at one byte. 

Even if p had been a float* ```a```'s value would not have been retrieved correctly since the way floats and ints are stored are not the same. 

This is explained [here](/pointers_in_cpp/code/2_strong_typing_pointers_and_void_pointer.cpp).

In the file step by step the following is explained: 

```cpp

int a = 1025; /* 1025 in binary = 00000000 00000000 00000100 00000001 */
int* p_int = &a;

cout << p_int << *p_int; /* 0x7fffffffdaa4; 1025 */
cout << p_int + 1 << *(p_int + 1); /* 0x7fffffffdaa8; -9564 (junk) */

//#############################################

char* p_char = (char*) p_int;

cout << (void*) p_char << (int) *p_char; /* 0x7fffffffdaa4; 1 */

cout << (void*) p_char << (int) *p_char; /* 0x7fffffffdaa5; 4 */

```

The reasoning for p_char displaying value as 1 and 4 respectively is that: 

1. 1025 in binary = 00000000 00000000 00000100 00000001

1. p_char initially points to least significant 8 bits. Hence we get the value 1. 

1. p_char+1 moves to the next 8 bits. Hence, we get the value 4. 

This is because seeing a character pointer the system only focusses on 8 bits even though the underlying value is of int (32 bits). 

This clearly explains the need for strong typedness in pointers. 

# void*

The void pointer can receive addresses from any other fundamental type or any other fundamental type pointer. But C++ only allows void* to display addresses and not values. This is because void* do not correspond to a specific type. So the system does not know how many bits to look at when trying to find a value in the address being pointed to by void*.

This is shown again [here](/pointers_in_cpp/code/2_strong_typing_pointers_and_void_pointer.cpp).