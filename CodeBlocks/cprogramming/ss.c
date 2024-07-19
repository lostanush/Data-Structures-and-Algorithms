//array representation of list
#include<stdio.h>
#include<stdlib.h>
#define LIST_SIZE 30
void main()
{
int *element=NULL;
int ch,i,j,n;
int insdata,deldata,moddata,found;
int top=-1;
element=(int*)malloc(sizeof(int)* LIST_SIZE);
while(1)
{
fflush(stdin);
printf("\n\n basic Operations in a Linear List......");
printf("\n 1.Create New List \t 2.Modify List \t 3.View List");
printf("\n 4.Insert First \t 5.Insert Last \t 6.Insert Middle");
printf("\n 7.Delete First \t 8.Delete Last \t 9.Delete Middle");
printf("\nEnter the Choice 1 to 10 : ");
scanf("%d",&ch);
switch(ch)
{
case 1:
top=-1;
printf("\n Enter the Limit (How many Elements):");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("\n Enter The Element [%d]:",(i+1));
scanf("%d",&element[++top]);
}
break;
case 2:
if(top==-1)
{
printf("\n Linear List is Empty:");
break;
}
printf("\n Enter the Element for Modification:");
scanf("%d",&moddata);
found=0;
for(i=0;i<=top;i++)
{
if(element[i]==moddata)
{
found=1;
printf("\n Enter The New Element :");
scanf("%d",&element[i]);
break;
}
}
if(found==0)

printf("\n Element %d not found",moddata);
break;
case 3:
if(top==-1)
printf("\n \n Linear List is Empty:");
else if(top==LIST_SIZE -1)
printf("\n Linear LIst is Full:");
for(i=0;i<=top;i++)
printf("\n Element[%d]is-->%d",(i+1),element[i]);
break;
case 4:
if(top==LIST_SIZE-1)
{
printf("\n Linear List is Full:");
break;
}
top++;
for(i=top;i>0;i--)
element[i]=element[i-1];
printf("\n Enter the Element:");
scanf("%d",&element[0]);
break;
case 5:
if(top==LIST_SIZE-1)
{
printf("\n Linear List is Full:");
break;
}
printf("\n Enter the Element:");
scanf("%d",&element[++top]);
break;
case 6:
if(top==LIST_SIZE-1)
printf("\n Linear List is Full:");
else if(top==-1)
printf("\n linear List is Empty.");
else
{
found=0;
printf("\n Enter the Element after which the insertion is to be made:");
scanf("%d",&insdata);
for(i=0;i<=top;i++)
if(element[i]==insdata)
{
found=1;
top++;
for(j=top;j>i;j--)
element[j]=element[j-1];
printf("\n Enter the Element :");
scanf("%d",&element[i+1]);
break;
}
if(found==0)
printf("\n Element %d Not Found",insdata);
}
break;
case 7:

if(top==-1)
{
printf("\n Linear List is Empty:");
break;
}
printf("\n Deleted Data-->Element :%d",element[0]);
top--;
for(i=0;i<=top;i++)
element[i]=element[i+1];
break;
case 8:
if(top==-1)
printf("\n Linear List is Empty:");
else
printf("\n Deleted Data-->Element :%d",element[top--]);
break;
case 9:
if(top==-1)
{
printf("\n Linear List is Empty:");
break;
}
printf("\n Enter the Element for Deletion :");
scanf("%d",&deldata);
found=0;
for(i=0;i<=top;i++)
if(element[i]==deldata)
{
found=1;
printf("\n Deleted data-->Element :%d",element[i]);
top--;
for(j=i;j<=top;j++)
element[j]=element[j+1];
break;
}
if(found==0)
printf("\n Element %d Not Found ",deldata);
break;
default:
free(element);
printf("\n End Of Run Of Your Program.........");
exit(0);
}
}
}
