#include<stdio.h>
struct Result
{
    int min;
    int max;
};
struct Result find_min_max(int arr[], int n)
{
    struct Result res;
    res.min = arr[0];
    res.max = arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>res.max)
        {
            res.max = arr[i];
        }
        else
        {
            res.min = arr[i];
        }
    }
    return res;
}
int main()
{
    int n;
    printf("Enter the size of an array: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        printf("enter array elem: ");
        scanf("%d",&arr[i]);
    }
    struct Result res=find_min_max(arr,n);
    printf("Min=%d\nMax=%d\n",res.min,res.max);
    return 0;
}