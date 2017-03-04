#include <iostream>

using namespace std;

int main()
{
    int a[5][5],m,n,i,j;
    cout<<"Enter the value of m and n: "<<endl;
    cin>>m>>n;
    cout<<"\n Enter the elements of matrix n: ";
    for (i=0;i<m;++i)
    for (j=0;j<n;++j)
    cin>>a[i][j];
    cout<<"\n Elements of matrix n is: \n";
    for (i=0;i<m;++i)
        {
            for (j=0;j<n;++j)
            cout<<a[i][j]<<" ";
            cout<<"\n";
        }



    return 0;
}
