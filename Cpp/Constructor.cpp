#include <iostream>
using namespace std;
 
class A {
    protected: int x;
    public: 
        A()      { x=0; }
        A(int a) { x=a; }
        A(A &a)  { x=a.x; }   
         void show(){
            cout<<x<<endl;
        }
};
class B : public A {
    int y;
    public: 
        B(int a,int b) : A(a){
            y=b;
        }
        void setx(int a) { x=a; }
        void sety(int b) { y=b; }
        void show(){
            cout<<x<<" "<<y<<endl;
        }
};
/// @brief 
/// @return 
int main()
{   
    B b1(10,20); 
    b1.show();
    A a1(b1);
    a1.show();
    A a2= a1;
    a2.show();

}