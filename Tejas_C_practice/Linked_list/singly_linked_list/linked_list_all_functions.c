#include<stdio.h>
#include<stdlib.h>
int cnt=0;
struct student
{
    int roll;
    struct student *link; //self referential structure to hold address of next node.
};
struct student *addfirst(struct student *head)
{
    //create newnode
    struct student *newnode=NULL;
    newnode=malloc(sizeof(struct student));
    if(newnode==NULL)
    {
        printf("Node not created...\n");
        return head;
    }
    //initialize newnode
    printf("Enter roll: ");
    scanf("%d",&newnode->roll);
    
    //initialise link of newnode NULL
    newnode->link = NULL;
    //link node to list
        newnode->link = head;
        head=newnode;
        cnt++;
    
    return head;

}
struct student *Addlast(struct student *head)
{
    //create newnode
    struct student *newnode = NULL;
    newnode=malloc(sizeof(struct student));
    if(newnode == NULL)
    {
        printf("Node not created...\n");
        return head;
    }
    //initialise the newnode
    printf("Enter roll: ");
    scanf("%d",&newnode->roll);
   
    newnode->link = NULL;
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
    temp->link = newnode;
    cnt++;
    return head;
}
struct student *Insert_at_position(struct student *head)
{
    int pos;
    printf("Enter the position: ");
    scanf("%d",&pos);
    if(pos<=0 || pos > cnt+1)
    {
        printf("Invalid position...\n");
        return head;
    }
    //create a newnode
    struct student *newnode = NULL;
    newnode=malloc(sizeof(struct student));
    if(newnode==NULL)
    {
        printf("Node not created....\n");
        return head;
    }
    //initialize node
    printf("Enter roll: ");
    scanf("%d",&newnode->roll);
    newnode->link= NULL;

    if(pos == 1)
    {
        //add at first
        newnode->link = head;
        head= newnode;
        cnt++;
    }
    else
    {
        struct student *temp=head;
        for(int i = 1; i < pos-1; i++)
        {
            temp=temp->link;
        }
        newnode->link=temp->link;
        temp->link=newnode;
        cnt++;
    }
    return head;
}
void Print(struct student *ptr)
{
    if(ptr == NULL)
    {
        printf("List is Empty...\n");
        return ;
    }
    printf("----------List-----------\n");
    while(ptr)
    {
        printf("| %d |-->",ptr->roll);
        ptr=ptr->link;
    }
    printf("| NULL |\n");
    printf("-----------------------\n");
}
struct student *deletefirst(struct student *head)
{
    if(head == NULL)
    {
        printf("List is Empty....\n");
        return head;
    }
    struct student *temp=head;
    head=head->link;
    free(temp);
    cnt--;
    return head;

}
struct student *Deletelast(struct student *head)
{
    if(head == NULL)
    {
        printf("List is Empty...\n");
        return head;
    }
    if(head->link == NULL)
    {
        head=head->link;
        free(head);
        cnt--;
    }
    else
    {
        struct student *temp=head;
        while(temp->link->link !=NULL)
        {
            temp=temp->link;
        }
        free(temp->link);
        temp->link = NULL;
        cnt--;
    }
    return head;
}
struct student *Delete_at_position(struct student *head)
{
    if(head==NULL)
    {
        printf("List is empty...\n");
        return head;
    }
    int pos;
    printf("Enter the position: ");
    scanf("%d",&pos);
    if(pos<=0 || pos > cnt)
    {
        printf("Invalid position....\n");
        return head;
    }
    if(pos == 1)
    {
        struct student *temp = head;
        head=head->link;
        free(temp);
        cnt--;
        return head;
    }

    struct student *temp=head, *prev=NULL;
    for(int i=1;i<pos;i++)
    {
        prev=temp;
        temp=temp->link;
    }
    prev->link=temp->link;
    free(temp);
    cnt--;
    return head;
}
struct student *Reverse(struct student *head)
{
    struct student *temp=head, *prev=NULL, *next=NULL;
    while(temp != NULL)
    {
        next=temp->link;
        temp->link=prev;
        prev=temp;
        temp=next;
    }
    head=prev;
    return head;
}
struct student *Sort(struct student *head)
{
    if(head==NULL)
    {
        printf("List is Empty....\n");
        return head;
    }
    if(cnt==1)
    {
        printf("Single Node,Already sorted....\n");
        return head;
    }
    for(int i=0;i<cnt-1;i++)
    {
        struct student *temp=head;
        for(int j=i+1;j<cnt;j++)
        {
            if(temp->roll > temp->link->roll)
            {
                int t=temp->roll;
                temp->roll=temp->link->roll;
                temp->link->roll=t;
            }
            temp=temp->link;
        }
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
        printf("a. addfirst\nA. Addlst\nd. deletefirst\nD. Deletelast\nP. Print\nN. Add_at_position\nX. Delete_at_position\nR. Reverse\nT. Total nodes\nE.exit\n");
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
            case 'S':head=Sort(head);
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