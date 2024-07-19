#include<stdio.h>

struct node {
    int data;
    struct node *next;
};

struct node* create(struct node*rear){
    rear=malloc (sizeof(struct node));
    int d;
    printf("Enter data : ");
    scanf("%d",&d);
    rear->data=d;
    rear->next=NULL;
    return rear;
}

struct node* view(struct node* front){
    struct node* ptr=front;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    return front;
}

struct node *enqueue(struct node*rear){
    int d;
    printf("Enter data : ");
    scanf("%d",&d);

    struct node*temp=malloc(sizeof(struct node));
    temp->data=d;
    temp->next=NULL;
    rear->next=temp;
    rear=temp;
    return rear;
}

struct node* dequeue(struct node * front){
    struct node *temp= front;
    front=front->next;
    free(temp);
    return front;
};

void main(){
    int ch;
    struct node*front=NULL;
    struct node*rear=NULL;

    printf("\n\n Queue usinf LL Code::");
    printf("\n__________\n");


    while(1){
        printf("\n\n Menu::\n");
        printf(" 1. Create \n 2. View \n 3. enqueue \n 4. dequeue \n");
        printf(" Select option = ");
        scanf("%d",&ch);

        switch(ch){

            case 1: front=rear=create(front); break;
            case 2: front= view(front);  break;
            case 3: rear= enqueue(rear);  break;
            case 4: front= dequeue(front);  break;

}}
}
