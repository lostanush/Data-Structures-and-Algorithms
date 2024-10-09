package GreedyAlgo;
import java.util.Arrays;

public class MaxSumAbsDiff {
    
    private static int maxSum(int n, int arr[]){
        Arrays.sort(arr);
        for(int i=0; i<n; i++){
            System.out.print(arr[i]+" ");
        }System.out.println();
        int[] arr2= new int[n];
        int c=0;

        int i=0,j=n-1;
        while(c<n){
            if(c%2==0){
                arr2[c]=arr[i];
                i++;
            }else {
                arr2[c]=arr[j];
                j--; 
            }
            c++;
        }
        for(int a=0; a<n; a++){
            System.out.print(arr2[a]+" ");
        }System.out.println();

        int absMax =0;
        for(int a=0; a<n; a++){
            int b = Math.abs(arr2[a]);
            absMax+= b;
        }
        return absMax;
    }
    public static void main(String[] args) {
        int n = 4; 
        int[] arr=  {1,2,4,8};
        System.out.println(maxSum(n,arr));
    }
}
