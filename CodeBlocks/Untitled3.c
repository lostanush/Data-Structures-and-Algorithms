#include<stdio.h>

int q[10],visited[10]={0,0,0,0,0,0,0,0,0,0}, a[10][10];
int rear=-1,front=-1;
int count=0;
int v,n;

void BFS(int v){
 printf("%d ",v);
 visited[v]=1;
 while(front<=rear){
    for(int i=0;i<n;i++){
        if(a[v][i]==1 && visited[i]==0){
            printf("%d ",i);
            visited[i]=1;
            rear++;
            q[rear]=i;
        }
    }
 }

 printf("%d\t",q[front]);
 front++;
 BFS(q[front]);

}


int main() {

 printf("\n enter the no of nodes ");
 scanf("%d",&n);
 for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        scanf("%d",&a[i][j]);
    }
 }

 for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        printf("%d\t",a[i][j]);
    }
    printf("\n");
 }
 printf("enter the starting vertex");
 scanf("%d",&v);

 BFS(v);

 return 0;
}
