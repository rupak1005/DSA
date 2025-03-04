#include <iostream>
using namespace std;
int main()
{
    int a[]={1,2,3,4,5};
    int *ptr=a;
    cout<<*(ptr+1)<<endl;//2
    cout<<*(ptr+3)<<endl;//4
    ptr++;
    cout<<*ptr<<endl;//2
    }
