#include<stdio.h>
#include<conio.h>
int flag=0;
int found=0;

///Input ---------------------------------------

void read (int arr[],int n) {
flag=1;
 printf(" Array :\n");
 for(int i = 0; i < n; i++){
  printf("  Enter [%dth] element : ",i+1);
  scanf("%d", &arr[i]);
 }
}

///Output --------------------------------------

void print(int arr[],int n) {
 if(flag==1){
  printf("\n\n Array :\n");
  for(int i = 0; i < n; i++){
   printf("  Element [%dth] : %d\n",i+1,arr[i]);
   }
 }
 else printf("\n Array not created !!");
}

///Modify --------------------------------------

void modify(int arr[],int n){
 if(flag==1){
  int a,b, found =0;
  printf("\n Enter the elements tobe modified = ");
  scanf("%d",&a);
  for(int i=0;i<n;i++){
   if (a==arr[i]){
    found =1 ;
    printf("  Enter new element = ");
    scanf("%d",&b);
    arr[i]=b;
    printf("   Array modification Successfully !!");
    break;
   }
  }
  if(found==0)
   printf("\n\n Element not found in the array !!");
 }
 else printf("\n Array not created !!");
}


//void intfirst(int arr[],int n)
///MainFunction --------------------------------------------------

void main() {
 int n,ch,arr[100];
 printf("\n\n Static Array Code::");
 printf("\n ______________________\n");
 while(1){
  printf("\n\n Menu::\n");
  printf(" 1. Create  4. Insert-Beginning  7. Delete-First \n");
  printf(" 2. View    5. Insert-Middle     8. Delete-Middle   \n");
  printf(" 3. Modify  6. Insert-End        9. Delete-Last  \n");
  printf(" Select option = ");
  scanf("%d",&ch);

  switch(ch){
   case 1:  printf("\n Enter the no. of elements: ");
            scanf("%d", &n);
            read(arr,n);
            break;
   case 2: print(arr,n); break;

   case 3: modify(arr,n); break;

   case 4:  //intfirst(arr,n);
            if (flag==1){
                if(n!=99){
                    n++;
                    for(int i=n;i>0;i--)
                        arr[i]=arr[i-1];
                    printf("\n Enter the [1th] element : ");
                    scanf("%d",&arr[0]);
                    printf("  Element added Successfully !!");
                }
            }
            else printf("\n Array not created !!");
            break;

   case 5:  //intmid(); break;
            if(flag==1){
                int e;
                printf("\n Enter the element after which the insertion is tobe made = ");
                scanf("%d",&e);
                for(int i=0;i<n;i++){
                    if(e==arr[i]){
                        n++;
                        for(int j=n;j>i;j--)
                            arr[j]=arr[j-1];
                        printf("  Enter the new element : ");
                        scanf("%d",&arr[i+1]);
                        printf("   Element added Successfully !!");
                    }
                }
            }
            else printf("\n Array not created !!");
            break;

   case 6:  //intend(); break;
            if(flag==1){
                    if(n!=99){
                        n++;
                        printf("\n Enter the [%dth] element : ",n);
                        scanf("%d",&arr[n-1]);
                        printf("  Element added Successfully !!");
                    }
            }
            else printf("\n Array not created !!");
            break;

   case 7:  //detfirst(); break;
            if (flag==1){
                for(int i=0;i<n;i++)
                    arr[i]=arr[i+1];
                n--;
                printf("\n Element deleted Successfully !!");
            }
            else printf("\n Array not created !!");
            break;

   case 8:  //detmid(); break;
            if(flag==1){
                printf("\n Enter the element tobe deleted = ");
                int d, found=0;
                scanf("%d",&d);
                for(int i=0;i<=n;i++){
                    if(d==arr[i]){
                        found =1;
                        printf("  Element [%dth] deleted Successfully !!",i+1);
                        n--;
                        for(int j=i;j<=n;j++)
                            arr[j]=arr[j+1];
                    }
                }
                if(found ==0)
                    printf("  Element not found !!");
            }
            else printf("\n Array not created !!");
            break;

   case 9:  //detend(); break;
            if (flag==1){
                n--;
                printf("\n Element deleted Successfully !!");
            }
            else printf("\n Array not created !!");
            break;

   default :
            printf("\n Invalid option selected !!");
  }
 }
}

