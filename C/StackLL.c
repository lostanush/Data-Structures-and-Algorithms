#include <stdio.h>
#include<malloc.h>
struct node
{
 int data;
 struct node *next;
};

struct node *head=NULL;


void main(){
    int count=0,choice,option=1,pushelement,popelement,position;

    while(1){
        printf("\nMenu :: \n1: push\n2: pop\n3: peep\n4: peek\n5: display\n Select option= ");
        scanf("%d",&choice);

        switch(choice){

            case 1:
                    struct node *ptr=malloc(sizeof(struct node));
                    if(ptr==NULL){
                        printf("\n node not created");}
                    count++;
                    printf("\n enter data : ");
                    scanf("%d",&pushelement);

                    ptr->data=pushelement;
                    ptr->next=NULL;

                    if(head==NULL)
                        head=ptr;
                    else{
                        ptr->next=head;
                        head=ptr;
                    }
                    printf("\n Insertion successfully!! \n");
                    break;
            case 2:
                    if(head==NULL){
                        printf("\nUnderflow");}
                    else{
                        struct node *popelement;
                        popelement=head;
                        head=head->next;
                        printf("\n deletion Successfully !!");
                                            }
                    break;
            case 3:
                    if(head==NULL)
                        printf("Underflow");

                    printf("\nenter position : " );
                    scanf("%d",&position);
                    if(position>count)
                        printf("wrong position");
                    else{
                        struct node *temp;
                        temp=head;

                        while(count!=position)
                            temp=temp->next;

                        printf("\n element at position %d from the top is %d",position,temp->data);
                        }
                        break;
            case 4:
                    if(head==NULL)
                        printf("Underflow");
                    else{
                        printf("\n peek operation started");
                        printf("\n element at the top of the stack is%d",head->data);
                        }
                    break;
            case 5:
                    if(head==NULL)
                        printf("Underflow");

                    else{
                        struct node *temp;
                        temp=head;
                        while(temp!=NULL){
                            printf("%d\n",temp->data);
                            temp=temp->next;
                        }
                    }
                    break;
            default:printf("\n Invalid choice");

        }
    }

}
