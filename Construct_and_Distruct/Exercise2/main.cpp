#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>

using namespace std;

class stock
{
    char author[50];
    char title[50];
    char pub[50];
    double price;
    int numcopies;
public:
    stock();
    int access_title(char a[]);
    void input();
    void getdata(int num);
};

stock ::stock()
{
    char author[50] = {"ABC"};
    char title[50] = {"EFG"};
    char pub[50] = {"HIJ"};
    price = 500;
    numcopies = 50;

}

int stock ::access_title(char a[])
{
    if(strcmp(title, a))
    {
        return 0;
    }
    else return 1;

}
void stock :: getdata(int num)
{
    if(numcopies >= num)
    {
        cout<<"\n Cost of "<<num<<"books is RS"<<(price*num);
    }
    else
        cout<<"\n Sorry these many copies are not available. ";

}
void stock::input()
{
    cout<<"\nTtitle: ";
    gets(title);
    cout<<"\nAuthor: ";
    gets(author);
    cout<<"\nPublisher: ";
    gets(pub);
    cout<<"\nPrice: ";
    cin>>price;
    cout<<"\nCopies Available: ";
    cin>>numcopies;
}

int main()
{
    stock obj[2];
    int n;
    char ttle[50];
    cout<<"Enter details of 3 books. ";
    for(int i=0;i<2;++i)
        obj[i].input();
    cout<<"\n";
    cout<<"\n Enter Title of required books. \n";
    gets(ttle);
    for(int i=0; i<2; i++)
    {
        if(obj[i].access_title(ttle))
        {
            cout<<"\nHow many copies?? ";
            cin>>n;
            obj[i].getdata(n);
        }
        else
            cout<<"Book unavailable";
    }
    return 0;
}
