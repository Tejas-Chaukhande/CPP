#include<stdio.h>
#include<stdlib.h>
struct student
{
    char *name;
    int roll;
    float marks;
};
int main()
{
    int n;
    printf("Enter the number of students: ");
    scanf("%d",&n);
    
    struct student *ptr[n];  //Array of pointer to structure
    
    for(int i=0;i<n;i++)
    {
        ptr[i]=(struct student *)calloc(1,sizeof(struct student));
        ptr[i]->name =(char *)calloc(20,sizeof(char));
    }
    
    for(int i=0;i<n;i++)
    {
        printf("Enter name, roll and marks: ");
        scanf("%s %d %f\n",&ptr[i]->name,&ptr[i]->roll,&ptr[i]->marks);
    }
    for(int i=0;i<n;i++)
    {
        printf("======Student information: %d\n======",i+1);
        printf("%s %d %f\n",ptr[i]->name,ptr[i]->roll,ptr[i]->marks);
    }
    return 0;
}