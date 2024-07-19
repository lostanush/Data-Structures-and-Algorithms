
// C++ program to demonstate the use of try,catch and throw
// in exception handling.
 
#include <iostream>
#include <stdexcept>
using namespace std;
 
int main()
{
    try {
        int n = 10;
        int d = 0;
        int r;
 
        if (d == 0) {
            throw runtime_error("Division by zero not allowed!");
        }
        r = n / d;
        cout << "Result after division: " << r << endl;
    }
    catch (exception e) {
        cout << "Exception " << e.what() << endl;
    }
    return 0;
}