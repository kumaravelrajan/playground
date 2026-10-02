#include <iostream>
#include <string>

using namespace std;

class myFloat{
    float myflt;

    public: 
    myFloat(){
        myflt = 0.1;
    }

    /* Functors in C++ are objects that can be called and executed like functions by overloading the function call operator () in a class or struct. This enables objects of such classes to be used syntactically just like regular functions, and they are therefore also called function objects. */
    void operator () (float value){
        myflt += value;
    }

    float getValue(){
        return myflt;
    }
};

int main () {

    myFloat obj_myFloat; 

    cout << obj_myFloat.getValue() << endl;

    /* Use of Functor/Function object */
    obj_myFloat(1.1);

    cout << obj_myFloat.getValue() << endl;

    obj_myFloat(0.5);

    cout << obj_myFloat.getValue() << endl;

	return 0;

}