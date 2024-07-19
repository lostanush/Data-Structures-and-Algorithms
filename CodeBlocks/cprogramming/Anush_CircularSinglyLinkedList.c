#include<stdio.h>
int data;
int i=0;
int pos;

struct node
{
    int data;
    struct node* link;
    struct node* prev;
};




//

struct node* print(struct node *head)
{
    i=0;
    struct node *ptr=head;
    printf("\n L-List :\n");
    do{
        i++;
       // printf("  Node [%dth] : %d\n",i,ptr->data);
        printf(" %d -> ",ptr->data);
        ptr = ptr->link;
    }while(ptr != head);
 return head;
}

//
struct node* intbeg(struct node *head)
{
    printf("\n Enter the [1th] Node data : ");
    scanf("%d",&data);

    struct node *ptr = head;

    while(ptr->link != head)
        ptr=ptr->link;

    struct node *temp = malloc(sizeof(struct node));

    temp->data=data;
    temp->link=head;
    temp->prev=ptr;

    ptr->link=temp;
    head->prev=temp;

    head= temp;

    printf("  Added Successfully !! \n");

return head;
}



//
struct node* intend(struct node*head)
{
    struct node *ptr,*temp;
    ptr=head;
    temp=malloc(sizeof(struct node));

    i=1;
    while(ptr->link!=NULL){
        ptr=ptr->link;
        i++;
    }

    printf("\n Enter the [%dth] Node data : ",i+1);
    scanf("%d",&data);

    temp->data=data;
    temp->link=head;
    temp->prev=ptr;

    head->prev=temp;

    //ptr->link =temp;
    printf("  Node added Successfully !! ");

return head;
}
//
struct node * intmid(struct node *head)
{

    int pos;
    printf("\n Enter the position to insert new node : ",pos);
    scanf("%d",&pos);

    printf("  Enter the [%dth] Node data : ",pos);
    scanf("%d",&data);

    if(pos==1){
       head = intbeg(head);
        return head;
        }
    else {
            struct node *curr=head, *temp= malloc(sizeof(struct node));
            struct node *ptr=head ;

            temp->data=data;
            temp->link=NULL;
            temp->prev=NULL;

            while(pos!=1){
                pos--;
                ptr=curr;
                curr=curr->link;
            }

            curr->prev=temp;
            temp->link=ptr->link;
            temp->prev=ptr;
            ptr->link=temp;

            printf("   Added Successfully !! \n");
         }

         return head ;
}
//
struct node* detbeg(struct node *head)
{
    printf("\n Deleted Successfully!! ");

    struct node *ptr=head;
    struct node *temp=head;

   while(ptr->link!=head){
      ptr=ptr->link;
   }

   head=head->link;
   head->prev=ptr;
   ptr->link =head;

   free(temp);


   return head;

}

//
struct node* detend(struct node *head)
{
    printf("\n Deleted Successfully!! ");

    struct node *curr = head;
    struct node *ptr = head;


    while(curr->link!=NULL){
        ptr=curr;
        curr=curr->link;
    }

    ptr->link=head;
    head->prev= ptr;

    free(curr);
    //curr->link=NULL;
    return head;

}


//
struct node * detmid(struct node *head)
{

    int pos;
    printf("\n Enter the position to delete node : ",pos);
    scanf("%d",&pos);
    printf("  Deleted Successfully!! ");

    struct node *curr= head;
    struct node *ptr= head;

    if(pos==1){
        head= detbeg(head);
        return head;
        }
    else {
            while(pos!=1){
                pos--;
                ptr=curr;
                curr=curr->link;
            }

            //ptr->link=curr->link;
            curr->link->prev=ptr;
            ptr->link= curr->link;


            free(curr);
            //curr=NULL;
        }
return head;

}

/*
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

*/

void main ()
{
    int ch;
    struct node *head= malloc(sizeof(struct node));
    head->data= NULL;
    head->link= head;
    head->prev= head;

    printf("\n\n Dubbly List Code::");
    printf("\n__________\n");


    while(1){
        printf("\n\n Menu::\n");
        printf(" 1. Create             2. View              3. Modify \n");
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

            case 2: head =print(head);
                    break;

            //case 3: head =modify(head);
                    break;

            case 4: head =intbeg(head);
                    break;

            case 5: head =intmid(head);
                    break;

            case 6: head=intend(head);
                    break;

            case 7: head=detbeg(head);
                    break;

            case 8: head= detmid(head);
                    break;

            case 9: head=detend(head);
                    break;

            default: head=printf("\n Invalid option selected !!");
                     break;

        }

    }
}

