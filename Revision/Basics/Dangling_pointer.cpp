#include<iostream>
using namespace std;
int *fun()
{
    static int x=10;
    return &x;
}
int main()
{
    int *ptr=fun();
    cout<<*ptr;
    return 0;
}