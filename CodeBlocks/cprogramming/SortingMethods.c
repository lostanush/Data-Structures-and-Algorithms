
#include<stdio.h>
#include<conio.h>

void insertionSort(int arr[], int size) {

    for (int step = 1; step < size; step++) {
        int key = arr[step];
        int j = step - 1;

        while (key < arr[j] && j >= 0) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}




void bubbleSort(int arr[], int size) {

    for (int step = 0; step < size - 1; step++) {

        for (int i = 0; i < size - step - 1; i++) {

            if( arr[i]> arr[i+1]) {

                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
}



int part(int arr[], int low, int high) {

    int pivot= arr[high];
    int i = low-1 ;

    for (int j = low; j < high; j++) {

        if (arr[j] <= pivot) {
            i++;
            int temp= arr[i];
            arr[i]= arr[j];
            arr[j]= temp;

        }
    }
    int temp= arr[high];
    arr[high]= arr[i+1];
    arr[i+1]= temp;

return (i + 1);
}




void quickSort(int arr[], int low, int high) {

    if (low < high) {
        int pi =   part(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
  }
}






void main(){

   int n,A[100],ch;
   printf("Enter the no. of elements:\n");
   scanf("%d",&n);

   printf("\nEnter %d elements:\n",n);
    for(int i=0;i<n;i++)
    scanf("%d",&A[i]);

    printf("\n[ Menu ] \n");
    printf("1. Insertion Sort \n");
    printf("2. Bubble Sort\n");
    printf("3. Quick Sort\n\n");
    printf("Select option = ");

    scanf("%d",&ch);

    switch(ch){
    case 1: quickSort(A,0,n-1); break;
    case 2: insertionSort(A,n);  break;
    case 3: bubbleSort(A,n);   break;
    }


   for (int i = 0; i < n; ++i) {
    printf("%d  ", A[i]);
  }
}

