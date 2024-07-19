#include<stdio.h>

void main(){
    int queue1[10];
    int queue2[10];
    int front1=0 , rear1=-1;
    int front2=0 , rear2=-1;
    int n;

    for(int i=0;i<10;i++){
        scanf("%d",&n);
        if(n%2==0){
            rear1++;
            queue1[rear1]=n ;}
        else {
            rear2++;
            queue2[rear2]=n ;}
    }

    for(front1 ;front1<=rear1;front1++){
        printf("%d ",queue1[front1]);
    }
    printf("\n");
    for(front2 ;front2<=rear2;front2++){
        printf("%d ",queue2[front2]);
    }

}
