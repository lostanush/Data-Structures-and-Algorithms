
#include <iostream>
using namespace std;
 
class Base {
protected:
    int x;    
};
class Derived : public Base {
protected:
    int y;
public: 
    void setx(int a) { x=a; }
    void sety(int b) { y=b; }
};
class Child : public Derived{
public: 
    void show() { cout<<"sum of x,y = "<<x+y; }
};

int main()
{
    Child geeks;
    //geeks.b = 3; 
    geeks.setx(3);
    //geeks.a = 4;
    geeks.sety(4);
 
    geeks.show();
    return 0;
}
