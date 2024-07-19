#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define maxsize 10
struct Node{
int data;
struct Node*next;
};
void push(struct Node** head, int data){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
    printf("Inserted %d\n",newNode->data);
}
void display(struct Node** head)
{
    struct Node* temp = *head;
             while(temp->next!=NULL){
             printf("%d ",temp->data);
             temp = temp->next;}
    printf("\n");
}
void peep(struct Node** head,int pos)
{
    struct Node* temp = *head;int cnt=0;
             while(cnt!=pos){

             temp = temp->next;
             cnt++;
             }
             printf("%d ",temp->data);
    printf("\n");
}
int main()
{
    int i,option=1,pushelement,delelement,position,choice,peekelement,pos,top=-1;
    struct Node* head = (struct Node*) malloc(sizeof(struct Node));
    head->next=NULL;
    while (option==1)
    {
        printf("\nenter\n1.push\n2.pop\n3.peek\n4.peep\n5.display");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("\nenter element=");
            scanf("%d",&pushelement);
            top++;
            push(&head,pushelement);

          break;
           case 2:
               printf("element %d is removed",head->data);
               top--;
               head=head->next;

           break;
           case 3:
           printf("\n element at top=%d",head->data);
          break;
           case 4:

               printf("enter element position");
               scanf("%d",&pos);
               if(pos>top)
               {
                   printf("wrong position");
                   break;
               }
            peep(&head,pos);
           break;
            case 5:printf("\nLinked List: ");
            display(&head);

            break;
        }

    }

}
