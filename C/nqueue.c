#include"stdio.h"
#include"stdlib.h"
int first=-1;
int last=-1;
int enqueue(int que[],int n)
{
    if(last==9)       // insertion by using last
    {
        printf("\n stack is full");
        return 0;
    }
    else
    {
        first=0;
        last++;
        que[last]=n;
        return 1;
    }
}
int dequeue(int que[],int * n)
{
    if(first==-1||first>last)      // deletion by using first
    {
        printf("stack is empty unable to pop.");
        return 0;
    }
    else
    {
        printf("\n%d is poped form queue.",que[first]);
        first++;
        return 1;
    }
}
void display(int que[])
{
    int i;
    if(first==-1&&last==-1)
    {
        printf("stack under flow\n");
    }
    else
    {
        for(i=first;i<=last;i++)
        {
            printf("%d\t",que[i]);
        }
    }
}

void main()
{
    int option,r,num,n;
    int queue[10];
    printf("\n   *MENU*\n");
    while(1)
    {
        printf("1.INSERTION AN ELEMENT QUEUE.\n2.DELETE AN ELEMENT IN QUEUE\n3.DISPLAY ELEMENTS IN QUEUE\n4.EXTIT\n");
        scanf("%d",&option);
        switch(option)
        {
       case 1:
            printf("enter an element to enterd:");
            scanf("%d",&num);
            r= enqueue(queue,num);
            if(r==1)
                printf("\n%d entered successfully .",num);
            break;
       case 2:
            r=dequeue(queue,&n);
            //printf("\n%d is poped form queue.",n);
            break;
       case 3:
            display(queue);
            break;
       case 4:
            exit(1);
       default:
         printf("invaild input");
         break;
        }

    }
}


