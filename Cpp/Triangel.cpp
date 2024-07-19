#include<iostream>
using namespace std;

class Triangle{
    int l,b;
public:
  void read();
  int Area();
  int Perimeter();
  void show ();
};
void Triangle :: read(){
    cout<<"enter the radius: "<<endl;
    cin>>l>>b;
}
 int Triangle:: Area() {
        return l*b;
    }
    
 int Triangle ::Perimeter() {
        return 2 *(l+b);
    }
    
void Triangle::show() {
        cout << "Circle with radius " <<l<<b<< endl;
        cout << "Area: " <<Area()<< endl;
        cout << "Perimeter: " <<Perimeter()<< endl;
    }
int main() {
    Triangle c1;
   c1.read();
    c1.show();
    return 0;
}