#include <iostream>

using namespace std;
int count = 0;
class alpha
{
public:
    alpha()
    {
        count ++;
        cout<<"\n No. of objects created. "<<count;
    }
    ~alpha()
    {
        cout<<"\n No. of objects destroyed. "<<count;
        count --;
    }
};
int main()
{
    cout<<"\n\n Enter main \n";
    alpha A1, A2, A3, A4;
    {
        cout<<"\n\n Enter Block 1\n";
        alpha A5;
    }

    {
    cout<<"\n\nEnter Block 2 \n";
    alpha A6;
    }

    cout<<"\n\nRe-Enter Main \n";

    return 0;
}
