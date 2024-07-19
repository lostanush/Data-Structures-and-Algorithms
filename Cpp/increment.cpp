#include<iostream>
using namespace std;

class increment {
    int count;
public: 
    increment(): count(0){}
    increment(int c): count(c){}
    void operator --();
    void operator --(int);   // Overloaded prefix decrement operator
    void operator -(increment); // Overloaded postfix decrement operator
    void operator /(increment);
    void operator *(increment); // Overloaded multiplication operator
};

void increment::operator--() {
    cout<<--count<<endl;
}
void increment::operator--(int) {
    cout<<count--<<endl;
}

void increment::operator-(increment a) {
    cout << count - a.count << endl;
}
void increment::operator*(increment a) {
    cout << count * a.count << endl;
}
void increment::operator/(increment a) {
    cout << count / a.count << endl;
}

int main() {
    increment a(2), b(3), c(4);

    int ch;
    cin>>ch;
    switch (ch)
    {
    case 1:
        a--;
        break;
        cout<<"hi";
    case 2: 
        --a;
        break;
    case 3: 
        c-a;
        break;
    case 4:
        c*b; break;
    case 5 : 
        c/a;
    
    default:
        break;
    }
    // Using overloaded operators
    --a;        // Calls prefix decrement operator
    b - 1;      // Calls postfix decrement operator
    a * b;      // Calls multiplication operator

    return 0;
}
