#include <iostream>

using namespace std;
class class_2;

class class_1
{
    int value_1;
public:
    void indata(int a)
    {
        value_1 = a;
    }
    void display(void)
    {
        cout<<value_1<<"\n";
    }
    friend void exchange(class_1 &,class_2 &);
};
class class_2
{
    int value_2;
public:
    void indata(int a)
    {
        value_2 = a;
    }
    void display(void)
    {
        cout<<value_2<<"\n";
    }
    friend void exchange(class_1 &,class_2 &);
};
void exchange(class_1 & x,class_2 & y)
{
    int temp =x.value_1;
    x.value_1 = y.value_2;
    y.value_2 = temp;
}

int main()
{
    class_1 C1;
    class_2 C2;
    C1.indata(100);
    C2.indata(200);
    cout<<"values Before exchange"<<"\n\n";
    cout<<"X= ";
    C1.display();
    cout<<"Y= ";C2.display();
    exchange(C1,C2);

    cout<<"\nValues after exchange: "<<"\n\n";
    cout<<"X= ";C1.display();
    cout<<"Y= ";C2.display();
    return 0;
}
