// #include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Array
{
    private: int *ptr, size;
    public: Array(); //constructor
            Array(int *, int);
            ~Array(); //destructor
            void display();
};
Array::Array()
{
    cout<<"In Default Constructor...\n";
    cout<<"Enter the size of an array: ";
    cin>>size;
    ptr = new int[size];   //creating array dynamically
    for(int i=0;i<size;i++)
    {
        cout<<"Enter array element: ";
        cin>>ptr[i];
    }
}
void Array::display()
{
    cout<<"Array: ";
    for(int i=0;i<size;i++)
    {
        cout<<ptr[i]<<" ";
    }
    cout<<endl;
}
Array::~Array()
{
    cout<<"In Destructor...\n";
}
Array::Array(int *arr, int n)
{
    size=n;
    ptr = new int[n];
    for(int i=0;i<n;i++)
    {
        ptr[i]=arr[i];
    }

}
int main()
{
    Array a1;
    a1.display();

    int *arr, n;
    cout<<"Enter size for another array: ";
    cin>>n;
    arr = new int[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter array ele: ";
        cin>>arr[i];
    }

    Array a2(arr,n);
    a2.display();
    return 0;
}