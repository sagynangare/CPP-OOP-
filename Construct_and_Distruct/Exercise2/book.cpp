#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>

using namespace std;

class book
{
    char **author[80];
    char **title[80];
    float *price;
    char **publisher[80];
    int *stock_copy;
    int size;
public:
    book();
    void book_details(int i);
    void buy(int i);
    int search();
};
book :: book()
{
    size = 4;
    author = new char *[80];
    title = new char *[80];
    publisher = new char *[80];

    for(int i =0; i<size; i++)
    {
        author[i] = new char[80];
        title[i] = new char[80];
        publisher[i] = new char[80];
    }
    stock_copy = new int[size];
    price = new float[size];

    title[0] = "Object Oriented Programming with C++";
    title[1] = "Programming with ANSI C";
    title[2] = "I too had a love story";
    title[3] = "Computer algorithm";

    author[0] = "Balgurusamy";
    author[1] = "Balgurusamy";
    author[2] = "Chetan Bhagat";
    author[3] = "Sahani";

    stock_copy[0] = 200;
    stock_copy[1] = 122;
    stock_copy[2] = 332;
    stock_copy[3] = 231;

    price[0] = 221.4;
    price[1] = 215.5;
    price[2] = 189.6;
    price[3] = 132.4;

}

void book ::book_details(int i)
{
    cout<<"*********Book Details**********";
    cout<<setw(15)<<"Title"<<setw(16)<<"Author Name"<<setw(18)<<"Stock Copy \n";
    cout<<setw(15)<<title[i]<<setw(16)<<author[i]<<setw(18)<<stock_copy[i]<<"\n";
}
int book ::search()
{
    char name[80],t[80];
    cout<<"Enter author name";
    gets(name);
    cout<<" and title of book in small letter: ";
    gets(t);
    int count = -1;
    int a,b;
    for (int i=0; i<size; i++)
    {
        a=strcmp(name, author[i]);
        b = strcmp(t,title[i]);
        if(a == 0&& b ==0)
            count = 1;
    }
    return count;
}
void book ::buy(int i)
{
    if(i<0)
        cout<<"This book is not available. \n";
    else
        book_details(i);
        cout<<"How many copies of this book you want ? ";
        int copy;
        cin>>copy;
        int remaining_copy;
        if(copy <stock_copy[i])
        {
            remaining_copy = stock_copy[i]-copy;
            float total_price;
            total_price = price[i]*copy;
            cout<<"Total price= "<<total_price<<"Rs. \n";
        }
        else
            cout<<"Sorry your required copies are not available";

}
int main()
{
    book b1;
    int result;
    result = b1.search();
    b1.buy(result);
    return 0;

}
