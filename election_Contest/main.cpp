#include <iostream>
#include<conio.h>

using namespace std;
const int size= 50;
int spballot;
class ballot
{
    int candidate;
    int ballot[5];
    int spballot;
    void getdisplay(void);
};
int ballot :: spballot;

    void ballot :: getdisplay(void)
    {
        cout<<"\n\n\n\n Enter how many candidates you want to make:- ";
        cin>>candidate;
        static_cast a,b,c,d,e;
        a=0;
        a=b=c=d=e;
        cout<<"\n Enter 1-5 integers \n";
        for(int i = 0; i<candidate; i++)
        {
            cin>>vote[i];
            switch(vote[i])
            {
                case 1:
                    ballot[a];
                    a++;
                    break;
                case 2:
                    ballot[b];
                    b++;
                    break;
                case 3:
                    ballot[c];
                    c++;
                    break;
                case 4:
                    ballot[d];
                    d++;
                    break;
                case 5:
                    ballot[e];
                    e++;
                    break;
                default : ++spballot;

            }
            }
            int choice;
            do
            {
                cout<<"\n\n\n\n Choices Available:\n";
                cout<<"\n 1) Scored By Ballot A \n";
                cout<<"\n 2) Scored By Ballot B \n";
                cout<<"\n 3) Scored By Ballot C \n";
                cout<<"\n 4) Scored By Ballot D \n";
                cout<<"\n 5) Scored By Ballot E \n";
                cout<<"\n 6) Spoilt Ballot \n";
                cout<<"\n 7) EXIT \n";
                cout<<"\n Enter your choice :- \n";
                cin>>choice;
                switch(choice)
                {
                    case 1: cout<<"Scored By Ballot A is "<<a;
                        break;
                    case 2: cout<<"Scored By Ballot B is "<<b;
                        break;
                    case 3: cout<<"Scored By Ballot C is "<<c;
                        break;
                    case 4: cout<<"Scored By Ballot D is "<<d;
                        break;
                    case 5: cout<<"Scored By Ballot E is "<<e;
                        break;
                    case 6: cout<<"Spoilt Ballot were  "<<spballot;
                        break;
                    case 7: goto end;

                }
                }while(1)
                end:

            }
int main()
{
    ballot o1;
    o1.getdisplay();

    return 0;
}
