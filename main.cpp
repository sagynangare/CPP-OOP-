#include <iostream>
#include<cmath>
using namespace std;

int main()
{
   /* int age;
    int ageTotal =0;
    int numberOfPersonEntered =0;

    cout<<"Enter a age of First person or -1 to quit: "<<endl;
    cin>>age;

    while(age != -1){

        ageTotal = ageTotal + age;
        numberOfPersonEntered ++;

        cout<<"Enter next person age or -1 to quit:"<<endl;
        cin>>age;
    }
    cout<<"Enter a Number of person Entered:"<<numberOfPersonEntered<<endl;
    cout<<"Average age of person:"<<ageTotal/numberOfPersonEntered<<endl;
    */
    int a;
    int p=10000;
    int r = 0.3;

    for (int day = 1; day<=20; day++){
        a = p * pow(1+r,day);
        cout<<day<<"---------"<< a << endl;


    }
    return 0;
}
