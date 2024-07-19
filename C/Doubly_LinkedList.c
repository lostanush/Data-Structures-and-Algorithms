#include<stdio.h>
#include<malloc.h>
struct node
{
int data;
struct node *next;
struct node *prev;
};
struct node *head;
struct node * create(struct node *head){
    int data;
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    printf("\nenter node data\n");
    scanf("%d",&data);
    ptr->data=data;
    ptr->next=NULL;
    ptr->prev=NULL;
    head=ptr;
    printf("Node created\n");
    return head;
}
struct node * addbigin(struct node *head){
     int data;
     struct node *ptr=(struct node *)malloc(sizeof(struct node));
     printf("\nenter node data\n");
     scanf("%d",&data);
     ptr->data=data;
     ptr->prev=NULL;
     ptr->next=head;
     head->prev=ptr;
     head=ptr;
     return head;
}
void displaylist(struct node *head){
    struct node *temp;
    temp=head;
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}
struct node * addend(struct node *head){
    struct node *temp;
    temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    int data;
     struct node *ptr=(struct node *)malloc(sizeof(struct node));
     printf("\nenter node data\n");
     scanf("%d",&data);
     ptr->data=data;
     ptr->next=NULL;
     ptr->prev=temp;
    temp->next=ptr;
    return head;

}
struct node * addafter(struct node *head){
    int data1,data;
    struct node *temp;
    temp=head;
    printf("enter data after u want to insert\n");
    scanf("%d",&data1);
    while(temp->data != data1)
        temp=temp->next;
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
     printf("\nenter node data\n");
     scanf("%d",&data);
     ptr->data=data;
     ptr->prev=temp;
     ptr->next=temp->next;
    temp->next=ptr;
    return head;
}
struct node * delbeg(struct node *head){
    struct node *ptr;
    ptr=head;
    head=head->next;
    head->prev=NULL;
    free(ptr);
    printf("\n node deleted from beginning");
    return head;
}
struct node * delend(struct node *head){
    struct node *ptr,*temp;
    temp=head;
    while(temp->next->next!=NULL)
     temp=temp->next;
    ptr=temp->next;
    temp->next=NULL;
    free(ptr);
    printf("\n node deleted from end");
    return head;
}
struct node * delspecificnode(struct node *head){
     struct node *ptr,*temp;
     int data1;
     printf("enter data to be deleted\n");
     scanf("%d",&data1);
     temp=head;
     while(temp->data!=data1)
         temp=temp->next;
    if(temp->next ==NULL){
        ptr = temp;
        free(ptr);
        head = NULL;
        printf("List empty");
        return head;
    }else if(temp->prev ==NULL){
        ptr = temp;
        head = temp->next;
        head->prev=NULL;
        free(ptr);
        printf("Successfully deleted");
        return head;
    }else{
        ptr = temp;
    temp->next->prev = temp->prev;
    temp->prev->next=temp->next;
    free(ptr);
    printf("node deleted");
    return head;
    }

}
int main(){
    int choice;
    char option='y';
    while(1){
        printf("\n enter choice\n");
        scanf("%d",&choice);
       switch(choice){
           case 1:head=create(head);
           break;
           case 2:head=addbigin(head);
           break;
           case 3:displaylist(head);
           break;
           case 4: head=addend(head);
           break;
           case 5:head=addafter(head);
           break;
           case 6:head=delbeg(head);
           break;
           case 7: head=delend(head);
           break;
           case 8:head=delspecificnode(head);
           break;
       }
       printf("\ndo u want to continue? y or n\n");
       fflush(stdin);
       scanf("%c",&option);
       if(option=='n'||option=='N'){
        printf("Execution stopped\n");
        break;
       }
    }
    return 0;
}
