#include<stdio.h>
//#include<conio.h>
struct node {
    int coef;
    int exp;
};

struct node * createpoly(struct node* ll
void main (){
    
    struct node* head= malloc(sizeof(struct node));
    printf("enter the coef. and power = ");
    scanf("%d%d",&head->coef,&head->exp);
    
    printf("\n%dx^%d",head->coef,head->exp);
    
}