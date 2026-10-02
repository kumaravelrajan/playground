#include <iostream>
#include <string>

using namespace std;

class Rectangle{
    double _length;
    double _breadth;

    public: 

    Rectangle(double l = 2.0, double b = 4.0){
        _length = l;
        _breadth = b;
    }

    double Area (){
        return _length * _breadth;
    }

    bool Compare (Rectangle rect_obj){
        return this->Area() > rect_obj.Area();
    }
};

int main () {

    Rectangle r1(3.0, 3.0), r2(4.0, 4.0);

    cout << "r1.Compare(r2) = " << r1.Compare(r2) << endl;

    if(r1.Compare(r2)){
        cout << "r1 has a bigger area" << endl;
    } else {
        cout << "r2 has a bigger area" << endl;
    }

	return 0;

}