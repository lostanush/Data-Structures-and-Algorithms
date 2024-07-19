
#include <iostream>
using namespace std;
 
class Shape {
protected:
    int count;    
};
class Sphere : public Shape {
protected:
    int radius;
    int minor,major;
public: 
    void set_circle(int a) {
        radius = a;
    }
    void set_ovel(int b , int c){
        minor = b;
        major = c;
    }
};
class Circle : public Sphere{
public: 
    void get_circle() { 
        cout<<"Radius = "<<radius<<endl; 
    }
    void c_area(){
        cout<<"Area of circle = "<<3.14*radius*radius<<endl;
    }
};
class Ovel : public Sphere{
public:
    void get_ovel() { 
        cout<<"minor_radius = "<<minor<<endl;
        cout<<"major_radius = "<<major<<endl; 
    }
    void o_area(){
        cout<<"Area of ovel = "<<3.14*major*minor<<endl;
    }
};

int main()
{
    Circle c1;
    c1.set_circle(3);
    c1.get_circle();
    c1.c_area();

    Ovel o1;
    o1.set_ovel(4,5);
    o1.get_ovel();
    o1.o_area();
    return 0;
}
