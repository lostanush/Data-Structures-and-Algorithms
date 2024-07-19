#include<stdio.h>
#include<malloc.h>
struct node{
    int data;
    struct node *next;
};

struct node *head;


void main(){


     printf("Hello world!");
    struct node * head ;
    head = malloc (sizeof (struct node));
    head-> data = 1;
    head-> next = head;



    struct node * a = head;

    do{
    printf(" %d ",a->data);
    a =a->next;
    }while(a!=head);
    printf("\n");


    //head=create(head);
    //displaylist(head);

    //head=addbigin(head);
    //displaylist(head);


}
