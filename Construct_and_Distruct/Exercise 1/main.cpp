#include <iostream>
#include<strings.h>
#include<conio.h>
using namespace std;

class String
{
    char *str;
    int length;
public:
    String()
    {
        length = 0;
        str = new char [length + 1] ;
    }
    String(char *s);
    void concat(String &m, String &n);
    String (String &x);
    void display();
};
String :: String(String &x)
{
    length = x.length + strlen(x.str);
    str = new char[length + 1];
    strcpy(str, x.str);
}

void String:: concat(String &m,String &n)
{
    length=m.length+n.length;
    delete str;
    str=new char[length+1];
    strcpy(str,m.str);
    strcat(str,n.str);
}
void String :: display( )
{
    cout<<str;
}
String::String (char *s)
{
    length = strlen(s);
    str = new char[length + 1];
    strcpy(str,s);
}

int main()
{
    String s1;
    String s2("Well done");
    String s3("Badly done");
    cout<<"\n";
    s2.display();
    cout<<"\n";
    s1.concat(s2,s3);
    s2=s3;
    cout<<"\n";
    s2.display();
    cout<<"\n";
    s1.display();
    cout<<"\n";

    return 0;
}


/*#include <iostream>
#include<strings.h>
using namespace std;

class string
{
    char *str;
    int length;
public:
    string()
    {
        length = 0;
        str = new char[length + 1];
    }
    String(char *s);
    void concat(string &m, string &n);
    String(string *x);
    void display();
};
string::string(string &x)
{
    length = x.length + strlen(x.str);
    str = new char[length + 1];
    strcpy(str,x.str);
}
void string :: concat(string &m, string &n)
{

    length = m.length + n.length;
    delete str;
    str = new char[length + 1];
    strcpy(str,m.str);
    strcat(str,n.str);

}
void string ::display()
{
    cout<<str<<"\n";
}

string :: string(char *s)
{
    length = strlen(s);
    str = new char[legth + 1];
    strcpy(str, s);

}

int main()
{
    String s1;
    String s2("Well Done");
    String s3("Badly done");

    s2.display()
    s1.concat(s2, s3);
    s2=s3;
    s2.display();
    s1.display();
    return 0;
}
*/
