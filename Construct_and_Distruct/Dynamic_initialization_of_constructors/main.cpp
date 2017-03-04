#include <iostream>

using namespace std;
class Fixed_deposite
{
    long int P_amount;
    int Years;
    float Rate;
    float R_value;
public:
    Fixed_deposite(){}
    Fixed_deposite(long int p, int y, float r=0.12);
    Fixed_deposite(long int p, int y, int r);
    void display(void);

};

Fixed_deposite ::Fixed_deposite(long int p, int y,float r)
{
    P_amount = p;
    Years = y;
    Rate = r;
    R_value = P_amount;
    for(int i=1; i<=y; i++)
    {
        R_value = R_value*(1.0+r);
    }
}
Fixed_deposite ::Fixed_deposite(long int p, int y, int r)
{
    P_amount = p;
    Years = y;
    Rate = r;
    R_value = P_amount;
    for(int i =1; i<=y; i++)
    {
        R_value = R_value*(1.0 + float(r)/100);

    }
}

void Fixed_deposite ::display(void)
{
    cout<<"\n"
        <<"Principal Amount = "<<P_amount<<"\n"
        <<"Return Amount = "<<R_value<<"\n";
}

int main()
{
    Fixed_deposite FD1,FD2,FD3;
    long int p;
    int y;
    float r;
    int R;

    cout<<"Enter amount, period, interest rate(in percent)"<<"\n";
    cin>>p>>y>>R;
    FD1 =Fixed_deposite(p,y,R);

    cout<<"Enter amount, period, interest rate(in Decimal)"<<"\n";
    cin>>p>>y>>r;
    FD2 =Fixed_deposite(p,y,r);

    cout<<"Enter amount and period "<<"\n";
    cin>>p>>y;
    FD3 = Fixed_deposite(p,y);

    cout<<"\nDeposit 1";
    FD1.display();

    cout<<"\nDeposit 2";
    FD2.display();

    cout<<"\nDeposit 3";
    FD3.display();

    return 0;
}
