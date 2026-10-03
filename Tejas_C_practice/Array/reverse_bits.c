#include<stdio.h>
int main()
{
    int n;
    printf("Enter the data: ");
    scanf("%d",&n);

    printf("Before reverse: ");
    for(int i=7;i>=0;i--)
    {
        printf("%d",(n>>i)&1);
        if(i==0 && i%4==0)
        {
            printf(" ");
        }
    }
    //------main logic-----
    int rev=0;
    for(int i=0;i<8;i++)
    {
        rev=rev<<1;
        rev=rev|(n&1);
        n=n>>1;
    }
    //---------------------
    printf("\nAfter reverse: ");
    for(int i=7;i>=0;i--)
    {
        printf("%d",(rev>>i)&1);   //here reverse is present in rev, num is 0 now.
        if(i==0 && i%4==0)
        {
            printf(" ");
        }
    }
    return 0;
}