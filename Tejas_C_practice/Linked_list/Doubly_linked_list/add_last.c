#include<stdio.h>
#include<stdlib.h>
int cnt=0;
struct student
{
    int roll;
    struct student *prev; //will hold the address of previous node
    struct student *link; //will hold the address of next node
};
struct student *Addlast(struct student *head)
{
    struct student *newnode=NULL;
    newnode = malloc(sizeof(struct student));
    if(newnode==NULL)
    {
        printf("Node not created...\n");
        return head;
    }
    printf("Enter the roll: ");
    scanf("%d",&newnode->roll);
    newnode->prev=NULL;
    newnode->link=NULL;
    if(head==NULL)
    {
        head=newnode;
        return head;
    }
    struct student *temp=head;
    while(temp->link!=NULL)
    {
        temp=temp->link;
    }
    temp->link = newnode;
    newnode->prev = temp;
    cnt++;
    return head;
}
void Print(struct student *ptr)
{
    if(ptr==NULL)
    {
        printf("List is empty...\n");
        return;
    }
    printf("\n-----------List-----------\n");
    while(ptr)
    {
        printf("| %d |-->",ptr->roll);
        ptr=ptr->link;
    }
    printf("|NULL|\n---------------------------\n");
}
struct student *addfirst(struct student *head)
{
    struct student *newnode=NULL;
    newnode=malloc(sizeof(struct student));
    if(newnode==NULL)
    {
        printf("Node not created....\n");
        return head;
    }
    printf("Enter the roll: ");
    scanf("%d",&newnode->roll);
    newnode->prev=NULL;
    newnode->link = NULL;

    if(head==NULL)
    {
        newnode->link = head;
        head= newnode;
        cnt++;
        return head;
    }
    newnode->link =head;
    head->prev=newnode;
    head=newnode;
    cnt++;
    return head;

}
int main()
{
    struct student *head=NULL;
    char ch;
    while(1)
    {
        printf("a. add_first\nA. Add_last\nP. Print\nE. Exit\n");
        char ch;
        printf("Enter the choice: ");
        scanf(" %c",&ch);
        switch(ch)
        {
            case 'A': head=Addlast(head);
            break;
            case 'a':head=addfirst(head);
            break;
            case 'P':Print(head);
            break;
            case 'E':exit(0);
            default:printf("Invalid choice....\n");
        }
    }
    return 0;
}