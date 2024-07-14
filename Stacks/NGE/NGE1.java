package Stacks.NGE;
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


/*
The next greater element for an element in the array is 
the first element to the right that is greater than the current element. 
If no such element exists, the answer is typically considered -1.

Example: 
Given an array arr = [4, 5, 2, 25], the next greater elements are:
For 4, the next greater element is 5.
For 5, the next greater element is 25.
For 2, the next greater element is 25.
For 25, there is no greater element to the right, so the next greater element is -1.

Approach : 
1> Initialize an empty stack.
2> Traverse the array from right to left.
3> For each element:
    While the stack is not empty and the element at the top of the stack is 
        less than or equal to the current element, pop the stack.
    If the stack becomes empty, the next greater element is -1.
    Otherwise, the next greater element is the element at the top of the stack.
    Push the current element onto the stack.
*/
