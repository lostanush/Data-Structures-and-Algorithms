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



// add at end 

struct node*  am(struct node* head, int data, int pos){
   
    struct node * curr = head;
    struct node * pre = head;
    
    
    while(pos!=1){
    pre= curr;
    curr= curr-> next;
    pos--;
    }
  
   struct node * b = malloc (sizeof (struct node));
   b-> data = data;
    
   pre->next = b;
   b->next = curr ;
    
   // printf("hello");
    return head;
}




struct node*  db(struct node* head){
   
   
   struct node * a = head;
   struct node * b = head; 
   
   while(a->next!=head)
   a =a->next;
   head =head->next; 
   
   free(b);
   b->next=NULL;
   a->next = head;
    
   // pritf("hello");
   return head;
}




struct node*  dd(struct node* head){
   
   
   struct node * curr = head;
   struct node * pre = head;
    
    
   while(curr->next!=head){
    pre= curr;
    curr= curr-> next;
   }
   
   pre->next= head; 
   
   free(curr);
   curr->next=NULL;
   //a->next = head;
    
   // pritf("hello");
   return head;
}




struct node*  dm(struct node* head,  int pos){
   
    struct node * curr = head;
    struct node * pre = head;
    
    
    while(pos!=1){
    pre= curr;
    curr= curr-> next;
    pos--;
    }
  
   
   pre->next = curr-> next;
    
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
    
    head = am(head,100,3);
    p(head);
    
    head= db(head);
    p(head);
    
    head =dm(head,3);
    p(head);
    
    

    return 0;
    
    
}