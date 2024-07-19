#include<stdio.h>
#include<conio.h>
int n;
int ch;
int a[10]; /* external array definition */


void read () {
 int i;
 extern  int a[10]; /* external array declaration */
 printf("\nEnter the no. of elements: ");
 scanf("%d", &n);
 printf("Enter the elements :\n");
 for(i = 0; i < n; i++)
  scanf("%d", &a[i]);
}



void print() {
 printf("\nARRAY: ");
 for(int i = 0; i < n; i++)
   printf("%d ", a[i]);
   printf("\n");
}



void sort(){
  printf("\nSorting...\n");
 int i=0;
 for(i=1;i<n;i++){
 int key= a[i];
 int j = i-1;
    while( key<a[j] && j>=0){
      a[j+1]= a[j];
      j--;
    }
    a[j+1]= key;
 }
}


//void intAtBig(){

//void intAtEnd(){

//void intAtMid(){



void main() {
 int ch;
 while(10){
  printf("\n--------------------------\n");
  printf("Menu:\n");
  printf("1. Create \n2. View\n3. Sort\nSelect option = ");
  scanf("%d",&ch);
  switch(ch){
   case 1: read(); break;
   case 2: print(); break;
   case 3: sort(); break;
   //case 4: intAtBig(); break;
  }
 }
}

