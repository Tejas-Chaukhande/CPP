#include<stdio.h>
int main()
{
    int n;
    printf("Enter the number: ");
    scanf("%d",&n);
    printf("Before reverse: %d\n",n);
    int rev=0;
    while(n>0)
    {
        rev=(rev*10)+(n%10);
        n=n/10;
    }
    printf("After reverse: %d",rev);
    return 0;
}