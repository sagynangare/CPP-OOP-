#include <iostream>
#include <string.h>
#include <conio.h>

using namespace std;

class bank
{
    char name[20];
    int ano;
    char atype[20];
    float bal;
public:
    void get(int no, char *n, char *t,float b)
    {
        strcpy(name,n);
        ano = no;
        strcpy(atype,t);
        bal = b;
    }
    float deposit()
    {
        float amt;
        cout<<"\n\nEnter Amount to deposite: ";
        cin>>amt;
        bal = bal+amt;
    }
    float withdraw()
    {
        float amt;
        cout<<"\n\nHow many Rupees wanna to withdraw? ";
        cin>>amt;
        bal = bal - amt;
        return bal ;
    }
    void display()
    {
        cout<<"\n\n Account number: "<<ano;
        cout<<"\n\nName: "<<name;
        cout<<"\n\nAccount Type: "<<atype;
        cout<<"\n\nAccount Balance"<<bal;
        cout<<"\n\nDeposite Amount: "<<deposit();
        cout<<"\n\nAfter withdraw amount bal "<<withdraw();

    }

};


int main()
{
    int n;
    char nm[20];
    char t[20];
    float a;
    bank bk;
    cout<<"Enter Account Number: ";
    cin>>n;
    cout<<"\n Enter Name: ";
    cin>>nm;
    cout<<"\n\nAccount Type: ";
    cin>>t;
    cout<<"\n\nEnter balance amount: ";
    cin>>a;
    bk.get(n,nm,t,a);
    bk.display();
    return 0;
}
