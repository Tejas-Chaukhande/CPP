//Calculate ascii values of both string and compare if same then it is anagram.
//time complexity is O(n)
#include<iostream>
using namespace std;
int main()
{
    int t;
    cout<<"Enter test cases: ";
    cin>>t;
    while(t--)
    {
        string s1,s2;
        cout<<"Enter main string: ";
        cin>>s1;
        cout<<"Enter sub string: ";
        cin>>s2;

        int sum1=0,sum2=0;
        //sum of all character in s1
        for(int i=0;s1[i]!='\0';i++)
            sum1=sum1+int(s1[i]);
        //sum of all character in s2
        for(int i=0;s2[i]!='\0';i++)
            sum2=sum2+int(s2[i]);

        cout<<"sum1: "<<sum1<<endl;
        cout<<"sum2: "<<sum2<<endl;
        //if sum equal means its anagram
        if(sum1==sum2)
            cout<<"Anagram"<<endl;
        else
            cout<<"Not an Anagram"<<endl;
    }
    return 0;
}