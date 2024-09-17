#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *link;
}node;
void insertBegin(node **p,int data){
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->link = *p;
    *p = newnode;
}
void insertEnd(node **head,int data){
    node *ptr,*temp;
    temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->link = NULL;
    if(*head==NULL)
        *head = temp;
    else{
        ptr = *head;
        while(ptr->link!=NULL){
            ptr = ptr->link;
        }
        ptr->link = temp;
    }
}
void insert_nth(node **head,int data,int posn){
    node *temp, *ptr;
    int i = 1;
    temp = (node*)malloc(sizeof(node));
    temp->data = data;
    if(*head==NULL||posn==1){
        temp->link = *head;
        *head = temp;
    } 
    else{
        ptr = *head;
        while(i<=posn-2 && ptr->link!=NULL){
            ptr = ptr->link;
            i++;
        }
        temp->link = ptr->link;
        ptr->link = temp;
    }
}
void deleteFirst(node **head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    node *temp = *head;
    *head = (*head)->link;
    free(temp);
}
void deleteEnd(node **head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    if ((*head)->link == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    node *ptr = *head;
    while (ptr->link->link != NULL) {
        ptr = ptr->link;
    }
    free(ptr->link);
    ptr->link = NULL;
}
void delete_nth(node **head, int posn) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    if (posn == 1) {
        deleteFirst(head);
        return;
    }
    node *ptr = *head;
    int i = 1;
    while (i < posn - 1 && ptr->link != NULL) {
        ptr = ptr->link;
        i++;
    }
    if (ptr->link == NULL || i != posn - 1) {
        printf("Invalid position.\n");
        return;
    }
    node *temp = ptr->link;
    ptr->link = ptr->link->link;
    free(temp);
}
void displayList(node *head){
    printf("List: ");
    while(head!=NULL){
        printf("%d -> ",head->data);
        head = head->link;
    }
    printf("NULL\n");
}
int main(){
    node *head = NULL;
    int ch,data,posn;
    printf("MAIN MENU\n");
    printf("-----------------\n");
    printf("1. Insert element at the beginning.\n");
    printf("2. Insert element at the end.\n");
    printf("3. Insert element at the n-th position.\n");
    printf("4. Delete the first element.\n");
    printf("5. Delete the last element.\n");
    printf("6. Delete element at the n-th position.\n");
    printf("7. Print the list\n");
    printf("8. Exit\n");
    while(1){
        printf("Enter the operation: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter the element to insert at the beginning: ");
                scanf("%d",&data);
                insertBegin(&head,data);
                break;
            case 2:
                printf("Enter the element to insert at the end: ");
                scanf("%d",&data);
                insertEnd(&head,data);
                break;
            case 3:
                printf("Which position you want to insert: ");
                scanf("%d",&posn);
                if(posn<1){
                    printf("Invalid position. Position must be >= 1.\n");
                    break;
                }
                printf("Enter the element to insert at %d position: ",posn);
                scanf("%d",&data);
                insert_nth(&head,data,posn);
                break;
            case 4:
                deleteFirst(&head);
                break;
            case 5:
                deleteEnd(&head);
                break;
            case 6:
                printf("Which position you want to delete: ");
                scanf("%d", &posn);
                if (posn < 1) {
                    printf("Invalid position. Position must be >= 1.\n");
                    break;
                }
                delete_nth(&head, posn);
                break;
            case 7:
                displayList(head);
                break;
            case 8:
                return 0;
            default:
                printf("Invalid operation. Please try again..\n");
        }
    }
    node *temp;
    while(head!=NULL){
        temp = head;
        head = head->link;
        free(temp);
    }
    return 0;
}