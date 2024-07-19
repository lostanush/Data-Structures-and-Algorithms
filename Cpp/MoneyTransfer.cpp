//Money Transfer

#include <iostream>
using namespace std;

class Account{
    int acc;
    float bal;
    public : 
        Account();
        Account(int,int);
        void show();
        void moneytransfer(Account &,int);
        
};
Account :: Account(){
    acc=00;
    bal= 0;
}
Account :: Account(int a,int b){
    printf("%p\n",&bal);
    acc=a;
    bal=b;
}
void Account :: show(){
    cout<<"Accno. = "<<acc<<endl<<"Balance = "<<bal<<endl;
}
void Account :: moneytransfer(Account &a,int tempbal){
    if ( tempbal > bal){
        cout<<"InSufficient Balance"<<endl;
    } else {
        bal = bal - tempbal;
        a.bal= a.bal + tempbal;
        printf("%p\n",&a.bal);
        cout<<"Transfer Successfully"<<endl;
    }
}
int main()
{
    int tempbal;
    cout<<endl;
    Account a(1,1000),b(2,1000);
    a.show();
    b.show();
    cout<<"Enter the amount you want to transfer from acc1 to acc2 : ";
    cin>>tempbal;
    a.moneytransfer(b,tempbal);ik
    a.show();
    b.show();

    return 0;
}
