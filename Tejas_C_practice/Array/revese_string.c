#include<stdio.h>
void Reverse(char *str,int size)
{
    int i=0,j=size-1;
    while(i<j)
    {
        char ch=str[i];
        str[i]=str[j];
        str[j]=ch;
        i++,j--;
    }
}
int main()
{
    char str[20];
    printf("Enter the string: ");
    scanf("%s",&str);

    int size=0;
    for(int i=0;str[i];i++)
    {
        size++;
    }
    printf("original: %s\n",str);
    Reverse(str,size);
    printf("Reversed: %s\n",str);
    return 0;
}