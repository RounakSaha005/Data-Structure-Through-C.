#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct node
{
    int data;
    struct node *next;
}Node;
int counter(Node *p)
{
    Node *r=p;
    int count=0;
    if(p!=NULL)
    {
        do
        {
            count++;
            p=p -> next;
        }
        while (p!=r);     
        return count;
    }
}
void insert_end(Node **p,int num)
{
    Node *q,*r;
    q=(Node*)malloc(sizeof(Node));
    q ->data=num;
    if(*p==NULL)
    {
        q -> next=q;
        *p=q;
    }
    else
    {
        r=*p;
        while(r -> next!=*p)
        {
            r=r -> next;
        }
        q -> next=*p;
        r -> next=q;
    }
}
void insert_begin(Node **p,int num)
{
    Node *q,*r;
    q=(Node*)malloc(sizeof(Node));
    q -> data=num;
    if(*p==NULL)
    {
        q -> next=q;
        *p=q;
    }
    else
    {
        r=*p;
        while(r -> next!=*p)
        {
            r=r ->next;
        }
        q -> next=*p;
        r ->next=q;
        *p=q;
    }
}
void insert_nth_pos(Node **p,int num,int pos)
{
    Node *q,*r;
    int i;
    if(counter(*p)+1<pos)
    {
        printf("Invalid position\n");
        return;
    }
    q=(Node*)malloc(sizeof(Node));
    q -> data=num;
    if(pos==1)
    {
        q ->next=q;
        *p=q;
    }
    else
    {
        r=*p;
        for(i=0;i<pos-2;i++)
        {
            r=r -> next;
        }
        q -> next= r ->next;
        r ->next=q;
    }
}
void delete_first(Node **p)
{
    Node *r=*p;
    if(*p==NULL)
    {
        printf("Null list!Deletion not possible\n");
    }
    else
    {
        if(r -> next == r)
        {
            free(r);
            *p=NULL;
        }
        else
        {
            while(r -> next!=*p)
            {
                r=r ->next;
            }
            r ->next=(*p) -> next;
            free(*p);
            *p=r -> next;
        }
    }
}
void delete_end(Node **p)
{
    Node *r;
    if(*p==NULL)
    {
        printf("Null list!Deletion not possible\n");
    }
    else if((*p) -> next == *p)
    {
        free(*p);
        *p=NULL;
    }
    else
    {
        r=*p;
        while(r-> next -> next !=*p)
        {
            r=r ->next;
        }
        free(r ->next);
        r ->next=*p;
    }
}
void delete_nth(Node **p,int pos)
{
    Node *r=*p,*t;
    int i;
    if(counter(*p)<pos)
    {
        printf("Invalid position\n");
        return ;
    }
    else if(pos==1)
    {
        delete_first(p);
    }
    else
    {
        for(i=0;i<pos-2;i++)
        {
            r=r -> next;
        }
        t=r ->next;
        r -> next=t -> next;
        free(t);
    }
}
void delete_data(Node **p,int num)
{
    Node *q,*r=*p,*s=*p;
    if(*p==NULL)
    {
        printf("Null list!Deletion not possible\n");
    }
    else
    {
        while(r -> data !=num)
        {
            r=r -> next;
        }
        q=r -> next;
        while(s -> next !=r)
        {
            s=s ->next;
        }
        s -> next=q;
        free(r);
    }
}
void display(Node *p)
{
    Node *r;
    if(p==NULL)
    {
        printf("Null list\n");
    }
    else
    {
        r=p;
        while(p -> next !=r)
        {
            printf("%d -> ",p ->data);
            p=p ->next;
        }
        printf("%d\n",p -> data);
    }
}
int main()
{
    Node *head=NULL;
    int choice,num,pos;
    char ch='Y';
    while(1)
    {
        printf("Enter 1 to insert a new node\n");
        printf("Enter 2 to insert a node at the beginning\n");
        printf("Enter 3 to insert at the nth position\n");
        printf("Enter 4 to delete the first node\n");
        printf("Enter 5 to delete the end node\n");
        printf("Enter 6 to delete the node at nth position\n");
        printf("Enter 7 to delete the node based on it's value\n");
        printf("Enter 8 to display the circular linked list\n");
        printf("Enter 9 to exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                while(toupper(ch)=='Y')
                {
                    printf("Enter the number\n");
                    scanf("%d",&num);
                    insert_end(&head,num);
                    fflush(stdin);
                    printf("CONTINUE(Y/N):");
                    scanf("%c",&ch);
                }
                break;
            case 2:
                printf("Enter the number\n");
                scanf("%d",&num);
                insert_begin(&head,num);
                break;
            case 3:
                printf("Enter the number\n");
                scanf("%d",&num);
                printf("Enter the position to enter the node\n");
                scanf("%d",&pos);
                insert_nth_pos(&head,num,pos);
                break;
            case 4:
                delete_first(&head);
                break;
            case 5:
                delete_end(&head);
                break;
            case 6:
                printf("Enter the position to delete the node\n");
                scanf("%d",&pos);
                delete_nth(&head,pos);
                break;
            case 7:
                printf("Enter the value to delete the node\n");
                scanf("%d",&num);
                delete_data(&head,num);
                break;
            case 8:
                display(head);
                break;
            case 9:
                printf("Exited\n");
                exit(0);
            default:
                printf("Invalid Input\n");
        }
    }
}