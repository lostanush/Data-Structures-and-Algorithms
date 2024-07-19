void main() {
 int n,ch,arr[100];
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

