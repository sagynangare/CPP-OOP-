#include <iostream>
#include <conio.h>
using namespace std;

int const size = 50;
class vector
{
    float d[size];
    int s;
public:
    void create(void);
    void modify(void);
    void multiply(void);
    void display(void);
};
void vector ::create(void)
{
    cout<<"\n\nEnter Array you want to create:- ";
    cin>>s;
    cout<<"Enter "<<s<<" Real Numbers. \n";
    for(int i =0; i<s;i++)
    {
        cin>>d[i];
    }
}
void vector :: modify(void)
{
    int mfy_value;
    float with;
    cout<<"\n Enter Location of array at which value is to be modified: ";
    cin>>mfy_value ;
    cout<<"Enter value with which you want to replace: " ;
    cin>>with;
    d[mfy_value] = with;
}
void vector::multiply(void)
{
    int mul;
    cout<<"\nEnter value with which you want to multiply";
    cin>>mul;
    for(int i =0; i<s; i++)
    {
        d[i] = d[i]*mul;
    }
}
void vector::display(void)
{
    cout<<"\n\n Display of Array\n";
    cout<<"(";
    for(int i= 0;i<s; i++)
    {
        cout<<d[i];
        if(i !=s-1)
        {
            cout<<" , ";
        }
    }
    cout<<")";
}
int main()
{
    vector o1;
    int choice;
    do
    {
        cout<<"\n1)   To create Vector Array";
        cout<<"\n2)   To modify Vector Array";
        cout<<"\n3)   To multiply Vector Array";
        cout<<"\n4)   To display Vector Array";
        cout<<"\n5)   Exit \n";
        cout<<"Enter your choice:- ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            o1.create();
            break;
        case 2:
            o1.modify();
            break;
        case 3:
            o1.multiply();
            break;
        case 4:
            o1.display();
            break;
        case 5:goto end;
        }

    }while(1);
    end:
    return 0;
}
