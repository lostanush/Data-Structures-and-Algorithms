#include<stdio.h>
#include<malloc.h>
struct node
{
int data;
struct node *next;
};

struct node *head=NULL;

struct node * create(struct node *head)
{   int data;
    head =(struct node *)malloc(sizeof(struct node));
    printf("\n enter node data : ");
    scanf("%d",&data);
    head->data=data;
    head->next=head;
    //head=ptr;
    return head;
}
struct node * addbigin(struct node *head)
{
     struct node *ptr=(struct node *)malloc(sizeof(struct node));
     struct node *ptr2=head;

     while(ptr2->next!=head){
        ptr2=ptr2->next;
     }
     int data;
     printf("\n enter node data : ");
     scanf("%d",&data);
     ptr->data=data;
     ptr->next=head;

     head=ptr;
     ptr2->next = head;
     return head;
}
void displaylist(struct node *head)
{
    printf("\n\n L-List :\n  ");
    struct node *temp;
    temp=head;

    while(temp->next!=head)
    {
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("%d -> ",temp->data);
    printf("%d",head->data);



}
struct node * addend(struct node *head)
{   struct node *temp;
    temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    int data;
     struct node *ptr=(struct node *)malloc(sizeof(struct node));
     printf("\n enter node data : ");
     scanf("%d",&data);
     ptr->data=data;
     ptr->next=head;
    temp->next=ptr;
    return head;

}

struct node * addafter(struct node *head)
{
    int data1,data;
    struct node *temp;
    temp=head;
    printf("enter data after u want to insert : ");
    scanf("%d",&data1);
    while(temp->data != data1)
    {
        temp=temp->next;
    }
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
     printf("\n enter node data : ");
     scanf("%d",&data);
     ptr->data=data;
     ptr->next=temp->next;
    temp->next=ptr;
    return head;

}
struct node * delbeg(struct node *head)
{

    struct node *ptr, *ptr2;
    ptr=head; ptr2=head;

    while(ptr2->next!=head)
        ptr2=ptr2->next;

    head=head->next;
    ptr2-> next = head;

    free(ptr);
    printf("\n node deleted from beginning");
    return head;

}
struct node * delend(struct node *head)
{
    struct node *ptr,*temp;
    temp=head;

    while(temp->next->next!=head)
    {
     temp=temp->next;
    }

    ptr=temp->next;

    temp->next=head;
    free(ptr);
    printf("\n node deleted from end");
    return head;
}
struct node * delspecificnode(struct node *head)
{
     struct node *ptr,*temp;
     int data1;
     printf("enter data to be deleted : ");
     scanf("%d",data1);
     temp=head;

     while(temp->next->data!=data1)
     {
         temp=temp->next;
     }
     ptr=temp->next;
     temp->next=temp->next->next;

        free(ptr);
    printf("end node deleted");
    return head;
}
void main()
{
    int choice;
    int option=1;


    printf("\n\n Circular Linked List Code::");
    printf("\n ______________________\n");

    while(option==1)
    {
        printf("\n\n Menu::\n");
        printf(" 1. Create\n 2. Insert-Beginning\n 3. View\n");
        printf(" 4. Insert-End \n 5. Insert-Middle\n 6. Delete-First\n");
        printf(" 7. Delete-Last\n 8. Delete-Middle\n");
        printf(" Select option = ");
        scanf("%d",&choice);

       switch(choice)
       {
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

       printf("\n do u want to continue? (1=continue) : ");
       fflush(stdin);
       scanf("%d",&option);

    }
}
