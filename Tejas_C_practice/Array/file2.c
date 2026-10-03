#include<stdio.h>
#include "file1.c"
extern int x;
int main()
{
    printf("%d",x);
    return 0;
}