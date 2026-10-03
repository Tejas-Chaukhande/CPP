#include<stdio.h>
#include<stdlib.h>
void Print(int *arr, int n)
{
    printf("Array: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",*(arr+i));
    }
    printf("\n");
}
void Sort(int *arr, int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

//time complexity is O(n)
int find_element(int *arr, int size, int ele)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i]==ele)
        {
            return -1;
        }
        if(ele>arr[i] && ele < arr[i+1])
        {
            return i+1;
        }
    }
}
int main()
{
    int n;
    printf("Enter the size of an array: ");
    scanf("%d",&n);
    int *arr=NULL;
    arr=malloc(n*sizeof(int));
    if(arr==NULL)
    {
        printf("Memory not allocated..\n");
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        printf("Enter element: ");
        scanf("%d",&arr[i]);
    }
    Print(arr,n);
    Sort(arr,n);
    Print(arr,n);
    int x;
    printf("enter the element to find in array: ");
    scanf("%d",&x);
    int r=find_element(arr,n,x);
    if(r==-1)
    {
        printf("Element found");
    }
    else
    {
        printf("Element not found\nBut it should be at %d position\n",r);
    }
    return 0;
}