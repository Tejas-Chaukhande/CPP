#include<stdio.h>
#include<stdlib.h>

struct student
{
    int roll;
    char name[20];
    struct student *link;
};

struct student* Addlast(struct student *head)
{
    struct student *newnode=malloc(sizeof(struct student));

    if(newnode==NULL)
    {
        printf("Node not created\n");
        return head;
    }

    newnode->link=NULL;

    printf("Enter roll: ");
    scanf("%d",&newnode->roll);

    printf("Enter name: ");
    scanf("%s",newnode->name);

    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        struct student *temp=head;

        while(temp->link!=NULL)
        {
            temp=temp->link;
        }

        temp->link=newnode;
    }

    return head;
}

void Print(struct student *ptr)
{
    if(ptr==NULL)
    {
        printf("List empty\n");
        return;
    }

    while(ptr)
    {
        printf("%d %s\n",
                ptr->roll,
                ptr->name);

        ptr=ptr->link;
    }
}

int main()
{
    struct student *head=NULL;

    char ch;

    while(1)
    {
        printf("\nA.Add P.Print E.Exit\n");

        scanf(" %c",&ch);

        switch(ch)
        {
            case 'A':
                head=Addlast(head);
                break;

            case 'P':
                Print(head);
                break;

            case 'E':
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}