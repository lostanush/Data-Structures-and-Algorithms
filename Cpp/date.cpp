#include<iostream>
using namespace std;

class Date{
    int date,month,year;
    public :
        Date():date(0),month(0),year(0) {}
        Date(int a,int b,int c):date(a),month(b),year(c) {}
        Date next();
        void show();
        bool checkleap();
};

Date Date :: next(){
    Date temp= Date(date,month,year);
    int flag=0;

//31-----------------------------------------------
    if(temp.month==1 || temp.month==3 || temp.month==5 || temp.month==7 || temp.month==8 || temp.month==10  ||temp.month==12){
        if(temp.date==31){
            temp.date= 1;
            flag++;
        }
        else 
           temp.date++;
    }

//30---------------------------------------------------
    if(temp.month==4 || temp.month==6 || temp.month==9 || temp.month==11){
        if(temp.date==30){
            temp.date= 1 ;
            flag=1;
        }
        else 
           temp.date++;
    }   

//28,29----------------------------------------------------------
    if(temp.month==2 ){
        if(checkleap()){
            if(temp.date==29){
                temp.date= 1 ;
                flag++;
            }    
            else 
                temp.date++;
        }
        else {
            if(temp.date==28){
                temp.date= 1;
                flag++;
            }    
            else 
                temp.date++;
        }
    }

//NEXTMONTH;
    if(flag==1){
        temp.month++;
        if(temp.month>12){
            temp.month=1;
            temp.year++;  
        }
    }  
    return temp;
}
bool Date :: checkleap(){
    if(year%400==0 || year%100!=0 && year%4==0)
        return true;
    else return false;
}
void Date :: show(){
    cout<<date<<" "<<month<<" "<<year<<endl;
}
int main()
{
    //write your code here...
    Date d1(31,12,2025);
    d1.show();
    Date d2 = d1.next();  
    d2.show();

    return 0;
}