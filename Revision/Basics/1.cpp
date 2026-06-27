#include<iostream>
using namespace std;
void call_by_val(int p, int q)
{
    int x=p;
    p=q;
    q=x;
}
void call_by_add(int *x, int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
void call_by_ref(int &x,int &y)
{
    int p=x;
    x=y;
    y=p;

}
int main()
{
    int x=10,y=20;
    call_by_val(x,y);
    cout<<"x: "<<x<<" "<<"y: "<<y<<endl;
    call_by_add(&x,&y);
    cout<<"x: "<<x<<" "<<"y: "<<y<<endl;
    call_by_ref(x,y);
    cout<<"x: "<<x<<" "<<"y: "<<y<<endl;

    return 0;
}