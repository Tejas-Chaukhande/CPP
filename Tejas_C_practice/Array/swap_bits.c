#include<stdio.h>
int main()
{
    int data;
    int bit1,bit2;
    printf("Enter the data: ");
    scanf("%d",&data);
    printf("Enter bit1 & bit2: ");
    scanf("%d %d",&bit1, &bit2);

    for(int i=7;i>=0;i--)
    {
        printf("%d",(data>>i)&1);
        if(i!=0 && i%4==0)
        {
            printf(" ");
        }
    }
    printf("\n");
    printf("%d\n",((data>>bit1)&1));
    printf("%d\n",((data>>bit2)&1));

    if(((data>>bit1)&1) != ((data>>bit2)&1))
    {
        // data^=((1<<bit1)|(1<<bit2));
        data= (data & (~((1<<bit1)|(1<<bit2)))) | (((data>>bit1)&1)<<bit2) | (((data>>bit2)&1)<<bit1);
    }

    for(int i=7;i>=0;i--)
    {
        printf("%d",(data>>i)&1);
        if(i!=0 && i%4==0)
        {
            printf(" ");
        }
    }

}