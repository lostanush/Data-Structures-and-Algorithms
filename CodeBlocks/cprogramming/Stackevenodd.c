#include<stdio.h>

void main(){
    int stack1[10];
    int stack2[10];
    int top1=-1;
    int top2=-1;
    int n;

    for(int i=0;i<10;i++){
        scanf("%d",&n);
        if(n%2==0){
            top1++;
            stack1[top1]=n ;}
        else {
            top2++;
            stack2[top2]=n ;}
    }
    for(top1 ;top1>-1;top1--){
        printf("%d ",stack1[top1]);
    }
    printf("\n");
    for(top2;top2>-1;top2--){
        printf("%d ",stack2[top2]);
    }

}
