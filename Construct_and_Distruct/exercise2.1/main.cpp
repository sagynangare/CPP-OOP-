#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <iomanip>

using namespace std;

class book
{
    char **author;
    char **title;
    float *price;
    char **publisher;
    int *stock_copy;
    int size;
public:
    book();
    void book_detail(int i);
    void buy(int i);
    int search();
};

book :: book()
{
    size=4;
    author=new char*[80];
    title=new char*[80];
    publisher=new char*[80];
    for(int i=0;i<size;i++)
    {
        author[i]=new char[80];
        title[i]=new char[80];
        publisher[i]=new char[80];
    }
    stock_copy=new int[size];
    price=new float[size];

    title[0]="object oriented programming with c++";
    title[1]="programming in ANSI C";
    title[2]="electronic circuit theory";
    title[3]="computer algorithm";

    author[0]="balagurusamy";
    author[1]="balagurusamy";
    author[2]="boyelstade";
    author[3]="shahani";

    stock_copy[0]=200;
    stock_copy[1]=150;
    stock_copy[2]=50;
    stock_copy[3]=80;

    price[0]=120.5;
    price[1]=115.75;
    price[2]=140;
    price[3]=180.5;
}
void book::book_detail(int i)
{
    cout<<" *********book detail **********\n";
    cout<<setw(12)<<"Title"<<setw(25)<<"Author Name"
    <<setw(18)<<"Stock copy\n";
    cout<<setw(15)<<title[i]<<setw(16)<<author[i]<<setw(15)
    <<stock_copy[i]<<"\n";

}
int book::search()
{
    char name[80],t[80];
    cout<<"Enter author name : ";
    gets(name);
    cout<<"and title of book in small letter : ";
    gets(t);

    int count=-1;
    int a,b;
    for(int i=0;i<size;i++)
    {
        a=strcmp(name,author[i]);
        b=strcmp(t,title[i]);
        if(a==0 && b==0)
            count=i;
    }
    return count;
}
void book::buy(int i)
{
    if(i<0)
        cout<<" This book is not available \n";
    else
    {
        book_detail(i);
        cout<<" How many copies of this book is required : ? ";
        int copy;
        cin>>copy;
        int remaining_copy;
        if(copy<=stock_copy[i])
        {
            remaining_copy=stock_copy[i]-copy;
            float total_price;
            total_price=price[i]*copy;
            cout<<"Total price = "<<total_price<<" Rs.\n";
        }
        else
            cout<<" Sorry your required copies is not available \n";
    }
}

int main()
{
    book b1;
    int result;
    result=b1.search();
    b1.buy(result);
    return 0;
}
