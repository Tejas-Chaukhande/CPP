#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int *arr=malloc(n*sizeof(int));

    for(int i=0;i<n;i++)
    {
        printf("Enter the array element: ");
        scanf("%d",&arr[i]);
    }
    printf("Array: ");
    for(int i=0;i<n;i++)
    {
        printf("%d",arr[i]);
    }
    printf("\n");
    //---------main logic------
    int j=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=0)
        {
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            j++;
        }
    }
    //--------------------------
    printf("Array: ");
    for(int i=0;i<n;i++)
    {
        printf("%d",arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}