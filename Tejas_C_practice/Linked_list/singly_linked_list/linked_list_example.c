#include<stdio.h>
#include<stdlib.h>
int cnt=0;
struct student
{
    int roll;
    char name[20];
    struct student *link; //self referential structure to store
};
struct student *addfirst(struct student *head)
{
    struct student *newnode=NULL;
    newnode=malloc(sizeof(struct student));
    if(newnode==NULL)
    {
        printf("Node not created...\n");
        return head;
    }
    newnode->link=NULL;
    printf("Enter roll: ");
    scanf("%d",&newnode->roll);
    printf("Enter the name: ");
    scanf("%19s",newnode->name);
    
    newnode->link=head;
    head=newnode;
    cnt++;
    return head;
}
struct student *Addlast(struct student *head)
{
    //create newnode
    struct student *newnode=NULL;
    newnode=calloc(1,sizeof(struct student));
    if(newnode==NULL)
    {
        printf("Node not created...\n");
        return head;
    }
    newnode->link =NULL;
    //initialize Node
    printf("Enter roll: ");
    scanf("%d",&newnode->roll);
    printf("Enter name: ");
    scanf("%19s",newnode->name);
    if(head==NULL)
    {
        head=newnode;
        cnt++;
        return head;
    }
    struct student *temp=head;
    while(temp->link != NULL)
    {
        temp=temp->link;
    }
    temp->link=newnode;
    cnt++;
    return head;
}
void Print(struct student *ptr)
{
    if(ptr==NULL)
    {
        printf("List is Empty...\n");
        return;
    }
    printf("\n------------List is-------------\n");
    while(ptr)
    {
        printf("%d %s\n",ptr->roll, ptr->name);
        ptr=ptr->link;
    }
    printf("----------------------------------\n");
}
struct student *deletefirst(struct student *head)
{
    if(head==NULL)
    {
        printf("list is empty...\n");
        return head;
    }
    struct student *temp=head;
    head=head->link;
    cnt--;
    free(temp);
    return head;
}
struct student *Deletelast(struct student *head)
{
    if(head==NULL)
    {
        printf("List is empty....\n");
        return head;
    }
    if(head->link == NULL)
    {
        free(head);
        head=NULL;
    }
    else
    {
        struct student *temp=head;
        while(temp->link->link != NULL)
        {
            temp=temp->link;
        }
        free(temp->link);
        temp->link=NULL;
    }
    cnt--;
    return head;
}
struct student *Insert_at_position(struct student *head)
{
    int n;
    printf("Enter the position to insert: ");
    scanf("%d",&n);
    if(n<=0 || n>cnt+1)
    {
        printf("Invalid position...\n");
        return head;
    }
    //create newnode
    struct student *newnode=malloc(sizeof(struct student));
    if(newnode==NULL)
    {
        printf("Node not created...\n");
        return head;
    }
    newnode->link = NULL;
    //initialize newnode
    printf("Enter the roll: ");
    scanf("%d",&newnode->roll);
    printf("Enter the name: ");
    scanf("%19s",newnode->name);
    if(n==1)
    {//add at 1st
        newnode->link=head;
        head=newnode;
        cnt++;
    }
    else
    {//add in between 2 nodes
        struct student *temp=head;
        for(int i=1;i<n-1;i++)
        {
            temp=temp->link;
        }
        newnode->link = temp->link;
        temp->link = newnode;
        cnt++;
    }
    return head;
}
struct student * Delete_at_position(struct student *head)
{
    if(head==NULL)
    {
        printf("List is Empty....\n");
        return head;
    }
    int n;
    printf("Enter the position: ");
    scanf("%d",&n);
    if(n<=0 || n>cnt)
    {
        printf("Invalid position...\n");
        return head;
    }
    if(n==1)
    {
        struct student *temp=head;
        head=head->link;
        free(temp);
        cnt--;
    }
    else
    {
        struct student *temp=head,*prev=head;
        for(int i=1;i<n;i++)
        {
            prev=temp;
            temp=temp->link;
        }
        prev->link=temp->link;
        free(temp);
        cnt--;
    }
    return head;

}
int main()
{
    struct student *head = NULL;
    char ch;
    while(1)
    {
        printf("\n---------MENU----------\n");
        printf("a. addfirst\nA. Addlst\nd. deletefirst\nD. Deletelast\nP. Print\nN. Add_at_position\nX. Delete_at_position\nT. Total nodes\nE.exit\n");
        printf("------------------------\n");
        printf("Enter the choice: ");
        scanf(" %c",&ch);
        switch(ch)
        {
            case 'a':head=addfirst(head);
            break;
            case 'A':head=Addlast(head);
            break;
            case 'N':head=Insert_at_position(head);
            break;
            case 'd':head=deletefirst(head);
            break;
            case 'D':head=Deletelast(head);
            break;
            case 'X':head=Delete_at_position(head);
            break;
            case 'R':head=Reverse(head);
            break;
            case 'P':Print(head);
            break;
            case 'T':printf("------------------------\nTotal nodes are: %d\n------------------------\n",cnt);
            break;
            case 'E':exit(0);
            default:printf("Invalid choice...\n");
        }
    }
    return 0;
}