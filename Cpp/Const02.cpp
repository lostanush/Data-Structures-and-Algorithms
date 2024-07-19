#include<iostream>
using namespace std;

class vector{
    int *v;
    int size;
    public:
        vector v = new int[size];
        (int); 
        
        vector(vector &v2){
        size= v2.size;
        v = new int[size];
        for(int i=0; i<size; i++){
            v[i] = v2.v[i];
            }
        }
~vector();
        void read(){
            cout<<"Enter arr values: ";
            for(int i=0; i<size; i++){
                cin>>v[i];
            }
        }
        void show(){
            for(int i=0; i<size; i++){
                cout<<v[i]<<" , ";
            }
        } 
};

vector::vector(int n){
    size=n; 
   
}

vector::

vector :: ~vector(){
    delete[] v;
}

int main()
{
    //write your code here...
    vector v1(3) ;
    v1.read();
    v1.show();    
    
    return 0;
}