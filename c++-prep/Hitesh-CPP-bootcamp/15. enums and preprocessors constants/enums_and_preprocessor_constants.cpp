#include <iostream>

using namespace std;

/* This is a preprocessor constant. It acts as simple text substitution. 

Preprocessor constants do not have a data type—it's simply text replacement.

There is no scope for these constants; they are available everywhere from the point of definition onward in the file.

They are not type-safe, unlike const or constexpr variables.

They can be undefined using #undef if needed. 

ALTERNATIVES - 
C++ prefers const or constexpr keywords for defining typed, scoped, and safer constants. However, #define is still widely used for certain compile-time configuration and conditional compilation scenarios.
*/
#define PI 3.14

/* Use of ENUMS */

/* Define an enum using the enum keyword, then list your named constants separated by commas. By default, LOW is 0, MEDIUM is 1, and HIGH is 2, but you can assign specific integer values as well. */

enum Level { LOW, MEDIUM, HIGH };

enum TextTypes {BOLD = 20, ITALICS = 40, UNDERLINE};


int main () {

	Level myLevel = Level::MEDIUM;

	cout << "Level myLevel = Level::MEDIUM -> " << myLevel << endl;

	cout << "Level::LOW = " << Level::LOW << "; Level::MEDIUM = " << Level::MEDIUM << "; Level::HIGH = " << Level::HIGH << ";\n";

	cout << "TextTypes::BOLD = " << TextTypes::BOLD << "; TextTypes::ITALICS = " << ITALICS << "; TextTypes::UNDERLINE = " << UNDERLINE << ";\n";
		

	return 0;

}