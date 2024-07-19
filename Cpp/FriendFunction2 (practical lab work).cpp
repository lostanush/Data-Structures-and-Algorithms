#include <iostream>
//#include <conio.h>
using namespace std;

class TWO;

class ONE {
    int num1;
    public:
        ONE(int a) {
            num1=a;
        }
        void show(){
            cout << num1 << endl;
        }
        friend int add(ONE, TWO);
};

class TWO {
    int num2; 
    public:
        TWO(int b) {
            num2 = b;
        }
        void show(){
            cout << num2 << endl;
        }
        friend int add(ONE a, TWO b) {
            return a.num1 + b.num2;
        } 
};

int main() {
    ONE obj1(5);
    TWO obj2(10);
    
    cout << "Sum: " << add(obj1, obj2) << endl;
    
    return 0;
}
