
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
