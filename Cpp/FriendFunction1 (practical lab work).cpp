
#include <iostream>
//#include <conio.h>
using namespace std;

class DB;

class DM {
    int meter=0, centimeter=0;
    
    public:
        DM(int a,int b){
            meter=a; centimeter=b;
    }
        
    void show(){
        cout<<"DM : meter is "<<meter<<" and centimeter is "<<centimeter<<endl;
    }
    
    friend DM add (DM ,DB );
    friend DB adds (DM ,DB );
};

class DB {
    int inch=0, foot=0; 
    
    public:
        DB(int a,int b){
            inch=b; foot=a;
    }
    
    void show(){
        cout<<"DB : foot is "<<foot<<" and inches are "<<inch<<endl;
    }
    
    friend DM add (DM ,DB );
    friend DB adds (DM ,DB );
};

DM add (DM a,DB b){
    int m=0;
    int cm=0;
    
    m= b.foot / 3.281;
    cm= b.inch / 2.54;
    
    m += a.meter;
    cm += a.centimeter;
    
    if(cm>100){
        m= m + cm/ 100;
        cm= cm % 100;
    }
    
    return DM(m,cm);
}

DB adds (DM a,DB b){
    int i=0;
    int f=0;
    
    i= a.meter * 3.281;
    f= a.centimeter * 2.54;
    
    i += a.meter;
    f += a.centimeter;
    
    if(i >12){
        f = f + i/ 12;
        i= i%12;
    }
    
    return DB(i,f);
}


int main()
{
    cout<<"Hello World"<<endl;
    DM a(1,1);
    DB b(1,1);
    
    a.show();
    b.show();
    cout<<endl;
    
    DM a1= add(a,b);
    a1.show();
    
    DB b2= adds(a,b);
    b2.show();
   
    return 0;
}

