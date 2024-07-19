#include<stdio.h>
#include<malloc.h>
struct node{
    int data;
    struct node *next;
};


void displaylist(struct node *head){
    struct node *temp=head;
    while(temp->next!=head)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d\n ",temp->data);


}


struct node * create(struct node *head)
{   int data;
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    printf("\n enter node data : ");
    scanf("%d",&data);
    ptr->data=data;
    ptr->next=head;
    head=ptr;
    return head;
}




struct node * addbigin(struct node *head)
{
     struct node *temp=head;
     while(temp->next!=head){
        temp=temp->next;
     }

     struct node *ptr=(struct node *)malloc(sizeof(struct node));
     int data;
     printf("\n enter node data : ");
     scanf("%d",&data);
     ptr->data=data;
     ptr->next=head;

     head=ptr;
     temp->next = head;
     return head;
}

int  main(){

    struct node *head=NULL;

    int data;
    struct node *ptr=malloc(sizeof(struct node));
    printf("\n enter node data : ");
    scanf("%d",&data);

    ptr->data=data;
    ptr->next=head;
    head=ptr;


    //head=create(head);
    displaylist(head);

    head=addbigin(head);
    displaylist(head);

return 0;
}
