#include<stdio.h>
struct node {
   int data;
   struct node* next
};



void p(struct node  *head){

    struct node * a = head;

    do{
    printf(" %d ",a->data);
    a =a->next;
    }while(a!=head);
    printf("\n");
}


struct node*  ab(struct node* head, int data){



    struct node * a = head;

    while(a->next!=head)
    a =a->next;


   struct node * b = malloc (sizeof (struct node));
    b-> data = data;
    b->next = head ;
    head = b  ;
    a->next = head;

   // printf("hello");
    return head;
}



// add at end

struct node*  ad(struct node* head, int data){



    struct node * a = head;

    while(a->next!=head)
    a =a->next;


   struct node * b = malloc (sizeof (struct node));
    b-> data = data;
    b->next = head ;

    a->next = b;

   // printf("hello");
    return head;
}






int main()
{
    printf("Hello world!");
    struct node * head ;
    head = malloc (sizeof (struct node));
    head-> data = 1;
    head-> next = head;

    //printf(" %d ",head->data);

    struct node * temp ;
    temp = malloc (sizeof (struct node));
    temp-> data = 2;
    head->next = temp;
    temp-> next = head  ;


    struct node * temp2 ;
    temp2 = malloc (sizeof (struct node));
    temp2-> data = 3;
    head->next->next = temp2;
    temp2-> next = head  ;

    printf("\n %d ",head->data);
    printf("\n %d ",temp->data);
    printf("\n %d \n",temp2->data);
    printf(" ===== \n");

    p(head);
    head = ab(head,0);
    p(head);
    ad (head, 4);
    p(head);



    return 0;


}
