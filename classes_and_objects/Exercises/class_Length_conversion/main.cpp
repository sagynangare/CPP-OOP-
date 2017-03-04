#include <iostream>
#define factor 0.3048
using namespace std;
class DB;
class DM
{
    float d;
public:
    void store(float x){d = x;}
    friend void sum(DM,DB);
    void show();
};
class DB
{
    float d1;
public:
    void store(float y){d1 = y;}
    friend void sum(DM,DB);
    void show();
};
void DM::show()
{
    cout<<"\n Distance = "<<d<<" meter or "<<d*100<<" centimeters \n";
}
void DB::show()
{
    cout<<"\n Distance = "<<d1<<" feet or "<<d1*12<<" inches. \n";
}
void sum(DM m, DB b)
{
    float sum;
    sum = m.d +b.d1*factor;
    float f;
    f = sum/factor;
    DM m1;
    DB b1;
    m1.store(sum);
    b1.store(f);
    cout<<"Press 1 to display result in meter \n"
        <<"Press 2 to display result in feet \n"
        <<"What is your choice? ";

    int test;
    cin>>test;
    if(test == 1)
        m1.show();
    else if(test == 2)
        b1.show();
}
int main()
{
    DM dm;
    DB db;
    dm.store(10.5);
    db.store(12.5);
    sum(dm,db);
    return 0;
}
