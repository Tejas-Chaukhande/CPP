#include<stdio.h>
#include<stdlib.h>
int main()
{
    int r,c,b;
    printf("Enter row,column and block: ");
    scanf("%d %d %d",&r,&c,&b);
    
    int ***ptr=(int ***)malloc(r*sizeof(int **)); //will allocate 2 blocks
    
    for(int i=0;i<r;i++)
    {
        ptr[i]=(int **)malloc(c*sizeof(int *)); //inside 2 block allocate 3 blocks
    }
    
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            ptr[i][j]=(int *)malloc(b*sizeof(int));
        }
    }
    
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            for(int k=0;k<b;k++)
        {
            printf("Enter the element [%d][%d][%d]",i,j,k);
            scanf("%d",&ptr[i][j][k]);
        }
        }
    }
    
    printf("Elements are: \n");
    
    for(int i=0;i<r;i++)
    {
        printf("Row %d:\n ",i);
        for(int j=0;j<c;j++)
        {
            printf("Column %d:\n", j);
            for(int k=0;k<b;k++)
            {
                printf("%d ",ptr[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    
    //free the memory
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            free(ptr[i][j]);
        }
        free(ptr[i]);
    }
    free(ptr);
}