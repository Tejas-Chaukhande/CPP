#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    printf("Enter the size of an array: ");
    scanf("%d",&n);

    int *arr=malloc(n*sizeof(int));
    if(arr==NULL)
    {
        printf("Memory not allocated...\n");
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        printf("Enter the array element: ");
        scanf("%d",&arr[i]);
    }
    printf("Array: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");


    //----------------------main logic 1-----------------------
    int large=-1;
    int sec_large=-1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>large)
        {
            sec_large=large;
            large=arr[i];
        }
        else if(arr[i]>sec_large)
        {
            sec_large=arr[i];
        }
    }
    //--------------------------------------------------------
    //-----------------------logic 2: find largest 1st then find 2nd largest------------------
    // int large=arr[0];
    // for(int i=1;i<n;i++)
    // {
    //     if(arr[i]>large)
    //     {
    //         large=arr[i];
    //     }
    // }
    // int sec_large=-1;
    // for(int i=1;i<n;i++)
    // {
    //     if(arr[i]>sec_large && arr[i]!=large)
    //     {
    //         sec_large=arr[i];
    //     }
    // }
    //------------------------logic 3: sort the array and 2nd largest will be arr[n-1]--------------------
    // for(int i=0;i<n-1;i++)
    // {
    //     for(int j=i+1;j<n;j++)
    //     {
    //         if(arr[i]>arr[j])
    //         {
    //             int temp=arr[i];
    //             arr[i]=arr[j];
    //             arr[j]=temp;
    //         }
    //     }
    // }
    // printf("Large: %d\n",arr[n-1]);
    // printf("Sec large: %d\n",arr[n-2]);
    //---------------------------------------------------------------
    printf("Large: %d\n",large);
    printf("Sec large: %d\n",sec_large);
    free(arr);

    return 0;
}