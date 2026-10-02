#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Corners{
    float a,b,c,d;
};

ostream& operator << (ostream &stream_obj, Corners corner_obj){
    /* We return ostream& because we still have a endl to be displayed back in main. Without ostream&, this raises an error. */

    stream_obj << corner_obj.a << " " << corner_obj.b << " " << corner_obj.c << " " << corner_obj.d;
    return stream_obj;
}

int main () {

    vector<int> int_vector;

    int_vector.push_back(2);
    int_vector.push_back(3);
    int_vector.push_back(4);
    int_vector.push_back(5);

    
    for(auto i = int_vector.begin(); i != int_vector.end(); ++i){
        cout << *i << endl;
    }

    vector<Corners> corners_vector;

    corners_vector.push_back({1, 2, 3, 4});
    corners_vector.push_back({5, 6, 7, 8});

    for(int i = 0; i < corners_vector.size(); ++i){
        cout << corners_vector[i] << endl;
    }
    
    
	return 0;

}