#include <iostream>
#include <iomanip>
#define size 10
char *serial[size] = {"1st","2nd","3rd","4th","5th","6th","7th","8th","9th","10th"};

using namespace std;
class bank
{
    char name[40];
    int ac_no;
    char ac_type[20];
    double balance;
public:
    int assign(void);
    void deposit(float b);
    void withdraw(float c);
    void displayon(void);
    void displayoff(void);
};
int bank :: assign(void)
{
    float initial;
    cout<<"You have to pay 500 RS to open your account \n"
        <<"You have to store atleast 500 RS to keep your account active \n"
        <<"If Yes press 1 \n"
        <<"If No press 0 \n";
        int test;
        cin>>test;
        if (test ==1)
        {
            initial = 500;
            balance = initial;
            cout<<"Enter name, account number, account type to create account \n";
            cin>>name>>ac_no>>ac_type;
        }
        else
            cout<<"Do nothing \n";
            return test;
}
void bank ::deposit(float b)
{
    balance +=b;
}
void bank ::withdraw(float c)
{
    balance -=c;
    if(balance<=500)
    {
        cout<<"Sorry your balance is not sufficient to withdraw "<<c<<" RS right now\n"
            <<"You have to store at least 500 RS to keep your account active. \n";
            balance +=c;
    }
}

void bank ::displayon(void)
{
    cout<<setw(12)<<name<<setw(17)<<ac_type<<setw(14)<<balance<<endl;
}
void bank ::displayoff(void)
{
    cout<<"Account has not been created. \n";
}

int main()
{
    bank account[size];
    int t[10];
    for(int i = 0; i<size; i++)
    {
        cout<<"Enter information for "<<serial[i]<<" customer. \n";
        t[i]= account[i].assign();
        if(t[i] ==1)
        {
            cout<<"Would you want to deposit: ? \n"
                <<"If No press 0(Zero) \n"
                <<"If Yes, Enter deposit amount: \n";
                float dp;
                cin>>dp;
                account[i].deposit(dp);
                cout<<" Would you want to withdraw: ? \n"
                    <<"If No, press 0(Zero)\n"
                    <<"If Yes, Enter withdrawal amount: \n";
                float wd;
                cin>>wd;
                account[i].withdraw(wd);
                cout<<endl<<endl;
        }
        else if(t[i] ==0)
        {
            cout<<"Thank your, see you again. \n";

        }
    }
    cout<<"See Details: "<<endl<<endl;
    cout<<setw(12)<<"Name"<<setw(20)<<"Account Type"<<setw(12)<<"Balance";
    for(int i=0; i<size; i++)
    {
        if(t[i] ==1)
        {
            account[i].displayon();
        }
        else if(t[i]==0)
        {
            account[i].displayoff();
        }
    }
    return 0;
}
