#include <iostream>

using namespace std;
class item
{
    static int count;
    int number;
public:
    void getdata(int a)
    {
        number = a;
        count++;
    }
    void getcount(void)
    {
        cout<<"Count: ";
        cout<<count<<"\n";
    }
};
int item ::count;
int main()
{
    item a,b,c;
    a.getcount();
    b.getcount();
    c.getcount();


    a.getdata(100);
    b.getdata(200);
    c.getdata(300);

    cout<<"\n After reading data"<<"\n\n";
    a.getcount();
    b.getcount();
    c.getcount();

    return 0;
}