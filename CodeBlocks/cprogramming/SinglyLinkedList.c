#include<stdio.h>
int data;
int i=0;
int pos;

struct node
{
    int data;
    int link;
};






void printll(struct node **head)
{
    i=0;
    struct node *ptr=*head;
    printf("\n L-List :\n");
    while(ptr!=NULL){
        i++;
        printf("  Node [%dth] : %d\n",i,ptr->data);
        ptr= ptr->link;
    }
}






void intbeg(struct node **head)
{
    printf("\n Enter the [1th] Node data : ");
    scanf("%d",&data);

    struct node *temp = malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;

    temp->link=*head;
    *head=temp;
    printf("  Added Successfully !! \n");
}

void intend(struct node**head)
{
    struct node *ptr,*temp;
    ptr=*head;
    temp=malloc(sizeof(struct node));

    i=1;
    while(ptr->link!=NULL){
        ptr=ptr->link;
        i++;
    }

    printf("\n Enter the [%dth] Node data : ",i+1);
    scanf("%d",&data);

    temp->data=data;
    temp->link=NULL;

    ptr->link=temp;
    printf("  Node added Successfully !! ");
}

void intmid(struct node **head)
{

    int pos;
    printf("\n Enter the position to insert new node : ",pos);
    scanf("%d",&pos);

    printf("  Enter the [%dth] Node data : ",pos);
    scanf("%d",&data);

    if(pos==1){
        intbeg(&head);
        }
    else {
            struct node *ptr=*head, *temp= malloc(sizeof(struct node));
            temp->data=data;
            temp->link=NULL;
            while(pos!=2){
                pos--;
                ptr=ptr->link;
            }
            temp->link=ptr->link;
            ptr->link= temp;
            printf("   Added Successfully !! \n");
         }
}

void detbeg(struct node **head)
{
    printf("\n Deleted Successfully!! ");

    struct node *ptr=*head;
    struct node *temp=*head;
    ptr = ptr -> link;
    free(temp);
    temp->link=NULL;
    *head = ptr;
}


void detend(struct node **head)
{
    printf("\n Deleted Successfully!! ");

    struct node *curr = *head;
    struct node *prev = *head;
    while(curr->link!=NULL){
        prev=curr;
        curr=curr->link;
    }
    prev->link=NULL;
    free(curr);
    curr->link=NULL;

}



void detmid(struct node **head)
{

    int pos;
    printf("\n Enter the position to delete node : ",pos);
    scanf("%d",&pos);
    printf("  Deleted Successfully!! ");

    struct node *curr= *head;
    struct node *prev= *head;

    if(pos==1){
        detbeg(&head);
        }
    else {
            while(pos!=1){
                pos--;
                prev=curr;
                curr=curr->link;
            }
            prev->link=curr->link;
            free(curr);
            curr=NULL;
        }
}


void modify(struct node **head)
{
    printf("\n Enter the position tobe modified : ");
    scanf("%d",&pos);

    printf("  Enter the [%dth] Node data : ",pos);
    scanf("%d",&data);

    struct node *temp= *head;
    while(pos!=1){
        pos--;
        temp=temp->link;
    }
    temp->data= data;

    printf("   Modified Successfully!! ");


}



void main ()
{
    int ch;
    struct node *head= malloc(sizeof(struct node));
    head->data= NULL;
    head->link= NULL;

    printf("\n\n Linked List Code::\n");


    while(1){
        printf("\n\n Menu::\n");
        printf(" 1. Create             2. View              3.  \n");
        printf(" 4. Insert-Beginning   5. Insert-Middle     6. Insert-End   \n");
        printf(" 7. Delete-First       8. Delete-Middle     9. Delete-Last  \n");
        printf(" Select option = ");
        scanf("%d",&ch);

        switch(ch){

            case 1: printf("\n Enter the [1th] Node data : ");
                    scanf("%d",&data);
                    head->data = data;
                    printf("  Element added Successfully !!");
                    break;

            case 2: printll(&head);
                    break;

            case 3: modify(&head);
                    break;

            case 4: intbeg(&head);
                    break;

            case 5: intmid(&head);
                    break;

            case 6: intend(&head);
                    break;

            case 7: detbeg(&head);
                    break;

            case 8: detmid(&head);
                    break;

            case 9: detend(&head);
                    break;

            default: printf("\n Invalid option selected !!");
                     break;

        }

    }
}
