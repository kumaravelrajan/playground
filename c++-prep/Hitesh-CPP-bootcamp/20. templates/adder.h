/* Purpose of these include guards - 

Suppose two headers include the same third header like this:

    // Grandparent.h
    #ifndef GRANDPARENT_H
    #define GRANDPARENT_H

    struct Foo {
        int member;
    };

    #endif // GRANDPARENT_H

    // Parent.h
    #include "Grandparent.h"

    // Child.cpp (includes both Grandparent.h and Parent.h (which includes Grandparent.h))
    #include "Grandparent.h"
    #include "Parent.h"

Without include guards in "Grandparent.h", the structure Foo would be defined twice when compiling "Child.cpp", causing a compilation error. With the include guard, the second inclusion of "Grandparent.h" is ignored, and the compiler sees only one definition of Foo. This pattern avoids multiple inclusions safely and is essential for any non-trivial C++ project.

Alternatively, a common modern practice is to use #pragma once which achieves the same effect but is not part of the C++ standard, though widely supported by major compilers.

*/

#ifndef adder_h
#define adder_h

int addme(int a, int b){
    return a + b;
}

float addme(float a, float b) {
    return a + b;
}

#endif /* adder_h */