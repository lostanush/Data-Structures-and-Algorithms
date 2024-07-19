#include<stdio.h>
#include<conio.h>

struct node {
  int data;
  struct node *next
};

struct node *front=NULL, *rear =NULL;



struct node * create(struct node *rear){
  int d;
  printf(" Enter the data : ");
  scanf("%d",&d);

  struct node *temp=(struct node *)malloc(sizeof(struct node));
  temp->data=d;
  temp->next=NULL;

  rear=temp;
  printf("Queue created !! \n");
  return rear;
}

struct node * enqueue(struct node *rear){
  int d;
  printf(" Enter the data : ");
  scanf("%d",&d);

  struct node *temp=(struct node *)malloc(sizeof(struct node));
  temp->data=d;
  temp->next=NULL;

  rear->next=temp;
  rear=temp;
  printf("Element added successfully ..");
  return rear;
}

struct node * dequeue(struct node *front){
  //int d;
  //printf(" Enter the data : ");
  //scanf("%d",&d);
  struct node *temp=front;
  front=front->next;
  free(temp);
  return front;
}

void display(struct node *front){
  //int d;
  //printf(" Enter the data : ");
  //scanf("%d",&d);
  struct node *temp=front;
  printf("\nQueue : ");
  while(temp!=NULL){
    printf("%d ",temp->data);
    temp=temp->next;
  }
  printf("\n");


}

void main(){
  int ch;
  while(1){
    printf("\n\nMEnu ::\n");
    printf("1.create \n2.enqueue\n3.dequeue\n4.display\nselect option :");
    scanf("%d",&ch);
    switch(ch){

  case 1 : rear= front = create(front);   break;
  case 2 : rear= enqueue (rear );   break;
  case 3 : front = dequeue( front );   break;
  case 4 : display(front ); break;
  default : printf("Invallid optin !!\n ");

      }
  }
}
