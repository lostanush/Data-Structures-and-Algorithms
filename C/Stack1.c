#include <stdio.h>
struct node{
    int data;
    struct node *next;
};

struct node *push(struct node *head){

    int d ;
    printf("Enter data : ");
    scanf("%d",&d);

    struct node *temp= malloc(sizeof(struct node));
    temp->data=d;
    temp->next=head;
    
    head=temp;
    return head;
}

struct node view(struct node head){
    //head = head->next;
    struct node *ptr= head;

    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

struct node *pop (struct node *head){
    struct node *temp= head;
    head=head->next;
    free(temp);
    return head;
}


struct node *create(struct node * head ){

    int d ;
    printf("Enter data : ");
    scanf("%d",&d);

    head = malloc(sizeof(struct node ));
    head->data=d;
    head->next= NULL;

}

void main()
{

    struct node * head = malloc(sizeof(struct node));

    int ch;
    while(1)
    {
        printf("\n0. create\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Quit\n");
        printf("\nEnter your Choice :: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 0 : head=create(head); break;
            case 1 : head= push(head); break;
            case 2 : head= pop (head); break;
            case 3 : head= view(head); break;
        }
    }


}