#include<stdio.h>
int my_strlen(char *str)
{
    int size=0;
    while(*str!='\0')
    {
        size++;
        str++;
    }
    return size;
}
int main()
{
    char str[10];
    printf("Enter the string: ");
    scanf("%s",&str);

    printf("Length: %d\n",my_strlen(str));
    printf("%s",str);

    return 0;
}
