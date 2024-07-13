package Stacks.NextGreaterElement;
import java.util.Stack;
import java.util.Arrays;

public class NGE1 {

    public static int[] NGE(int[] arr){
        int n= arr.length;
        int[] NGE = new int[n];
        Arrays.fill(NGE,-1);
        Stack <Integer> s = new Stack<>();

        for(int i=n-1; i>=0 ; i--){
            while (!s.isEmpty() && s.peek()<= arr[i]) {
                s.pop();                
            }
            if(!s.isEmpty()){
                NGE[i]=s.peek();
            }
            s.push(arr[i]);
        }
        return NGE;
    }
    public static void main(String[] args) {
        int arr[] = {4,5,2,25};
        int NGE[] = NGE(arr);
        System.out.println(Arrays.toString(NGE));
    }
}
