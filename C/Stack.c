#include <stdio.h>
#define maxsize 10

void main() {
    int stack[maxsize],i,top=-1,choice,option=1,pushelement,delelement,position,peepelement;

    while(option==1){
        printf("\nMenu :: \n1: push\n2: pop\n3: peep\n4: peek\n5: display\n Select option= ");
        scanf("%d",&choice);

        switch(choice){

            case 1:
                    if(top==maxsize-1){
                        printf("\nStack overflow !!");
                        break;}
                    else{
                        printf("  enter element : ");
                        scanf("%d",&pushelement);
                        top++;
                        stack[top]=pushelement;
                        break;  }
            case 2:
                    if(top==-1){
                        printf("\n stack underflow !!");
                        break;}
                    else{
                        printf("\n Deletion Successfully !!");
                        delelement=stack[top];
                        top--;
                        break;  }
            case 3:
                    if(top==-1){
                        printf("\n stack underflow !!");
                        break;  }
                    else{
                        printf("\n enter the position of element from top : ");
                        scanf("%d",&position);
                        if(position>maxsize)
                            printf("\n wrong position selected !");
                        else {
                            peepelement=stack[top-position+1];
                            printf("\n element at position %d is %d .",position,peepelement);    }}
            case 4:
                    if(top==-1){
                        printf("\n stack underflow !!");
                        break;}
                    else{
                        printf("\nelement at the top is %d ",stack[top]);
                        break;}
            case 5:
                    if(top==-1){
                        printf("\n stack underflow !!")                   ;
                        break;  }
                    else{
                        printf("\n Array :: ");
                        for(i=0;i<=top;i++)
                        printf("%d ",stack[i]);
                        break;
                        printf("\n");
                        }
            default:
                    printf("\n Invalid Option !!");
                    break;
        }

    }

}
