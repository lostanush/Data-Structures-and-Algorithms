#include<stdio.h>
#include<conio.h>

struct student {
    int mark1,mark2,mark3;
};

int main(){
  struct student s[3];
  int total[3];
  float per[3];
  struct student *p;
  p=&s;

  for(int i=0;i<3;i++){
    printf("\n Enter Marks of 3 subjects for student [%d] : ",i+1);
    scanf("%d%d%d",&(p+i)->mark1,&(p+i)->mark2,&(p+i)->mark3);
  }
  for(int i=0;i<3;i++){
    total[i]  = (p+i)->mark1+(p+i)->mark2+(p+i)->mark3;
    temp[i] = float(total[i])/300;
    percent[i]= temp[i]*100;
  }
  for(int i=0;i<3;i++){
    printf("\n Student [%d] :\n  total = %d\n  percentage = %d\n",i+1,total[i],percent[i]);
  }

 }
