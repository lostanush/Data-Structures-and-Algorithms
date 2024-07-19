#include<stdio.h>
#include<conio.h>

struct node{
  int data;
  struct node *next;
};



int createnode(int data){
  struct node *newnode = malloc(sizeof(struct node ));
  newnode->data =data;
  newnode->data =NULL;
  return newnode;

}


void printdata(struct node*head ){
 if(head ==NULL)
    printf("Linked list empty ");
 struct node* ptr = NULL;
 ptr = head ;
 while (ptr!= NULL){
    printf("%d ",ptr->data);
    ptr = ptr-> next;
 }
}





void IntEnd(struct node*head ,int data)
{

    struct node *ptr,*temp;
   ptr=head;
  temp = malloc (sizeof(struct node));

  temp  -> data =data;
  temp -> next = NULL;

  while( ptr->next !=NULL){
     ptr= ptr->next;
  }
  ptr->next = temp;
}




void IntBeg(struct node**head ,int data){
  struct node *ptr= malloc (sizeof(struct node));

  ptr -> data =data;
  ptr -> next = NULL;

  ptr -> next = *head ;
  *head = ptr;

}



void IntMid(struct node * head,int data,int pos){
   struct node *ptr = head;
   struct node *ptr2 = malloc(sizeof(struct node));
   ptr2->data =data;
   ptr2->next =NULL;

   pos--;
   while(pos!=1){
     ptr = ptr->next;
     pos--;
   }
   ptr2->next = ptr->next;
   ptr->next = ptr2;

}

void main(){
 int ch, data ;

  struct node *head = NULL;
  head = malloc(sizeof(struct node));

 while(10){



    printf("  MENU ::\n");
    printf(" 1.Create \n 2. view \n 3. insert Beginning \n 4. insert at mid \n 5. insert at end \n");
    printf(" Select option = ");
    switch(ch){

    case 1 :
        printf("enter first data : ");
        scanf("%d",&data);
        head = createnode(data);
        break;
    case 2 :
        printnode(head);
        break;
    case 3 :
        printf(" Enter the data tobe entered : ");
        int e;
        scanf("%d",&e);
        IntBeg(&head,e);
        break;
    case 4 :
        printf(" Enter the data tobe entered : ");
        int f;
        scanf("%d",&f);
        printf(" Enter the position : ");
        int g;
        scanf("%d",&g);

        IntMid(head,f,g);
        break;

    case 5 :
        printf(" Enter the data tobe entered : ");
        int h;
        scanf("%d",&h);
        IntEnd(head,e);
        break;

    }
 }

}
