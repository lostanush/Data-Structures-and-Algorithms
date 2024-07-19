// c program for BFS
#include <stdio.h>
int q[10],visited[10],n,i,j,a[10][10],front=-1,rear=-1,count=0,v;
void BFS(int v)
{
 count++;
 if(count==1)
 {
 front=rear=0;
 q[front]=v;
 visited[v]=1;
 }
 while(front<=rear)
 { //q[front]=v;
 //visited[v]=1;
 for(i=0;i<n;i++)
 {
 if(a[v][i]==1 && visited[i]==0)
 {
 rear++;
 q[rear]=i;
 visited[i]=1;

 }
 }
 printf("%d\t",q[front]);
 front++;
  if (count==n)
    printf("Finished ");
 BFS(q[front]);
 }
 }
int main() {
 printf("\n enter the no of nodes");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
 for(j=0;j<n;j++)
 {
 scanf("%d",&a[i][j]);
 }
 }
 for(i=0;i<n;i++)
 {
 for(j=0;j<n;j++)
 {
 printf("%d\t",a[i][j]);
 }
 printf("\n");
 }
 printf("enter the starting vertex");
 scanf("%d",&v);
 BFS(v);

 return 0;
}
