#include <iostream>
#include <iomanip>
#define size 8
using namespace std;
class vector
{
    float *p;
public:
    void create_vector(void);
    void set_element(int i,float value);
    friend void add(vector v1,vector v2);
};
void vector::create_vector(void)
{
    p = new float[size];
}
void vector ::set_element(int i, float value)
{
    p[i] = value;
}
void add(vector v1,vector v2)
{
    float *sum;
    cout<<"Sum[ "<<size<<"]=(";
    sum = new float[size];
    for(int i=0;i<size;i++)
    {
        sum[i]=v1.p[i] + v2.p[i];
        if(i == size-1)
        {
            cout<<sum[i]<<",";
        }
        else
            cout<<sum[i]<<",";
    }
    cout<<")"<<"\n";
}

int main()
{
    vector x1, x2, x3;
    x1.create_vector();
    x2.create_vector();
    x3.create_vector();
    cout<<"Enter "<<size<<" elements of First vector: \n";
    for(int i= 0; i<size; i++)
    {
        float v;
        cin>>v;
        x1.set_element(i,v);
    }
        cout<<"Enter "<<size<<" elements of Second vector: \n";
    for(int i= 0; i<size; i++)
    {
        float v;
        cin>>v;
        x2.set_element(i,v);
    }
    add(x1,x2);
    return 0;
}
