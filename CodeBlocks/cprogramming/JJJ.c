//array representation of list
#include&lt;stdio.h&gt;
#include&lt;stdlib.h&gt;
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
printf(&quot;\n\n basic Operations in a Linear List......&quot;);
printf(&quot;\n 1.Create New List \t 2.Modify List \t 3.View List&quot;);
printf(&quot;\n 4.Insert First \t 5.Insert Last \t 6.Insert Middle&quot;);
printf(&quot;\n 7.Delete First \t 8.Delete Last \t 9.Delete Middle&quot;);
printf(&quot;\nEnter the Choice 1 to 10 : &quot;);
scanf(&quot;%d&quot;,&amp;ch);
switch(ch)
{
case 1:
top=-1;
printf(&quot;\n Enter the Limit (How many Elements):&quot;);
scanf(&quot;%d&quot;,&amp;n);
for(i=0;i&lt;n;i++)
{
printf(&quot;\n Enter The Element [%d]:&quot;,(i+1));
scanf(&quot;%d&quot;,&amp;element[++top]);
}
break;
case 2:
if(top==-1)
{
printf(&quot;\n Linear List is Empty:&quot;);
break;
}
printf(&quot;\n Enter the Element for Modification:&quot;);
scanf(&quot;%d&quot;,&amp;moddata);
found=0;
for(i=0;i&lt;=top;i++)
{
if(element[i]==moddata)
{
found=1;
printf(&quot;\n Enter The New Element :&quot;);
scanf(&quot;%d&quot;,&amp;element[i]);
break;
}
}
if(found==0)

printf(&quot;\n Element %d not found&quot;,moddata);
break;
case 3:
if(top==-1)
printf(&quot;\n \n Linear List is Empty:&quot;);
else if(top==LIST_SIZE -1)
printf(&quot;\n Linear LIst is Full:&quot;);
for(i=0;i&lt;=top;i++)
printf(&quot;\n Element[%d]is--&gt;%d&quot;,(i+1),element[i]);
break;
case 4:
if(top==LIST_SIZE-1)
{
printf(&quot;\n Linear List is Full:&quot;);
break;
}
top++;
for(i=top;i&gt;0;i--)
element[i]=element[i-1];
printf(&quot;\n Enter the Element:&quot;);
scanf(&quot;%d&quot;,&amp;element[0]);
break;
case 5:
if(top==LIST_SIZE-1)
{
printf(&quot;\n Linear List is Full:&quot;);
break;
}
printf(&quot;\n Enter the Element:&quot;);
scanf(&quot;%d&quot;,&amp;element[++top]);
break;
case 6:
if(top==LIST_SIZE-1)
printf(&quot;\n Linear List is Full:&quot;);
else if(top==-1)
printf(&quot;\n linear List is Empty.&quot;);
else
{
found=0;
printf(&quot;\n Enter the Element after which the insertion is to be made:&quot;);
scanf(&quot;%d&quot;,&amp;insdata);
for(i=0;i&lt;=top;i++)
if(element[i]==insdata)
{
found=1;
top++;
for(j=top;j&gt;i;j--)
element[j]=element[j-1];
printf(&quot;\n Enter the Element :&quot;);
scanf(&quot;%d&quot;,&amp;element[i+1]);
break;
}
if(found==0)
printf(&quot;\n Element %d Not Found&quot;,insdata);
}
break;
case 7:

if(top==-1)
{
printf(&quot;\n Linear List is Empty:&quot;);
break;
}
printf(&quot;\n Deleted Data--&gt;Element :%d&quot;,element[0]);
top--;
for(i=0;i&lt;=top;i++)
element[i]=element[i+1];
break;
case 8:
if(top==-1)
printf(&quot;\n Linear List is Empty:&quot;);
else
printf(&quot;\n Deleted Data--&gt;Element :%d&quot;,element[top--]);
break;
case 9:
if(top==-1)
{
printf(&quot;\n Linear List is Empty:&quot;);
break;
}
printf(&quot;\n Enter the Element for Deletion :&quot;);
scanf(&quot;%d&quot;,&amp;deldata);
found=0;
for(i=0;i&lt;=top;i++)
if(element[i]==deldata)
{
found=1;
printf(&quot;\n Deleted data--&gt;Element :%d&quot;,element[i]);
top--;
for(j=i;j&lt;=top;j++)
element[j]=element[j+1];
break;
}
if(found==0)
printf(&quot;\n Element %d Not Found &quot;,deldata);
break;
default:
free(element);
printf(&quot;\n End Of Run Of Your Program.........&quot;);
exit(0);
}
}
}
