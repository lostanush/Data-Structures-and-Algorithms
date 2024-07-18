/*
 *  Que 1)  PushAtBottom     :  pushAtBottom
 *  Que 2)  reverse a String :  reverseString
 *  Que 3)  reverse a Stack  :  reverseStack
 *  Que 4)  stock span       :  stockPlan / calculateSpan
 *  Que 5)  next greatest no.:  NGE
 *  Que 6)  valid parantheses:  isValid
 *  Que 7)  double parantheses: 
 *  Que 8)  Histogram : 
 */

import java.util.Stack;
public class StackQues {

    public static void printStack(Stack<Integer>s){
        while (!s.isEmpty()) {
            System.out.print(s.peek()+" ");
            s.pop();
        }
    }

    public static void pushAtBottom(Stack<Integer> s, int data) {
        if (s.isEmpty()) {
            s.push(data);
            return;
        }
        int top = s.pop();
        pushAtBottom(s, data);
        s.push(top);
    }
    // Code to reverse a String using Stacks. 
    public static String reverseString(String str){
        Stack<Character> s =new Stack<>();
        int idx =0 ;
        while(idx<str.length()){
            s.push(str.charAt(idx));
            idx++;
        }
        StringBuilder result = new StringBuilder();
        while(!s.isEmpty()){
            char ch = s.pop();
            result.append(ch);
            idx--;
        }
        return result.toString();
    }

    //reverse a Stack
    public static Stack<Integer> reverseStack(Stack<Integer>s ){
        Stack <Integer> rev= new Stack<>();
        while(!s.isEmpty()){
            rev.push(s.pop());
        }
        return rev;
    }

    
    //Stock Span Problem
    //Find the Maximum No.of consecutive days for which price <= todays price 
     
    /*   shradhas method ~ hard / not understood by me !     
    public static void stockSpan(int stocks[],int span[]){
        Stack<Integer> s =new Stack<>();
        span[0]=1;
        s.push(0);

        for(int i=1; i<stocks.length; i++){
            int currPrice= stocks[i];
            while (!s.isEmpty() && currPrice > stocks[s.peek()]) {
                s.pop();
            }
            if(s.isEmpty())
                span[i]=i+1;
            else {
                int preHigh =s.peek();
                span[i]= i-preHigh;
            }
            s.push(i);
        }
    }*/

    // easy method ------
    static class Pair {
        int price;
        int days;

        Pair(int price, int days) {
            this.price = price;
            this.days = days;
        }
    }
       
   public static void calculateSpan(int stocks[],int span[]) {
        //List<Integer> ans = new ArrayList<>();
        Stack<Pair> s = new Stack<>();

        for (int i=0; i<stocks.length; i++) {
            int days = 1;
            while (!s.isEmpty() && s.peek().price <= stocks[i]) {
                days += s.peek().days;
                s.pop();
            }
            s.push(new Pair(stocks[i], days));
            span[i] = days;
        }
        return;
    }


        /* MYMETHOD: ;)
        int arr[]=new int[span];
        for(int i=0;i<span;i++){
            arr[i]=1;
        }
        for(int i=0 ; i<span; i++){
            for(int j=0; j<i; j++ ){
                if(stock[j]<=stock[i] ){
                    arr[i]+=1;
                }
                if(stock[j]> stock[i])
                    continue;
            }
        }
        return arr;
        /
        
    }

     * 
     * 
     * 
    */
    


    public static void NGE(int arr[], int n){
        Stack<Integer> s = new Stack<>();
        int i = 0;
        int element, next;
        
        s.push(arr[0]);  /* push the first element to stack */
        
        for (i = 1; i < n; i++) {   // iterate for rest of the elements
            next = arr[i];
            if (s.isEmpty() == false) {
                element = s.pop();
                while (element < next) { 
                    System.out.println(element + " --> "+ next);
                    if (s.isEmpty() == true)
                        break;
                    element = s.pop();
                }

                if (element > next)
                    s.push(element);
            }
            s.push(next);
        }

        /* After iterating over the loop, the remaining
           elements in stack do not have the next greater
           element, so print -1 for them */
        while (s.isEmpty() == false) { //j++;
            element = s.pop();
            next = -1;
            System.out.println(element + " -- " + next);
        } 
        //System.out.println(j);
    }
    ///////////////////////////////////////////////////////////////
    //valid brackets
    public static boolean isValid(String str){
        Stack<Character> s= new Stack<>();
        for(int i=0; i<str.length(); i++){
            char ch= str.charAt(i);
            if(ch=='(' || ch=='{' || ch=='['){  //opening
                s.push(ch);
            }
            else {
                if(s.isEmpty()){
                    return false;
                }
                if( s.peek()=='(' && ch==')'||
                    s.peek()=='{' && ch=='}'||
                    s.peek()=='[' && ch==']' ){
                        s.pop();
                } else {
                    return false;
                }
            }
        }
        if(s.isEmpty())
            return true;
        else
            return false;
    }

    public static void main(String[] args) {
        Stack<Integer> s = new Stack<>();

        // Adding nodes to the stack
        s.push(10);
        s.push(20);
        s.push(30);

        // Push 100 at the bottom of the stack
        pushAtBottom(s, 100);

        // Displaying the stack
        printStack(s);

        String hell =new String();
        hell= "Hello WOrld";
        hell = reverseString(hell);
        System.out.println("\n"+hell);

        //reverse Stack;
        s.push(10);
        s.push(20);
        s.push(30);
        s= reverseStack(s);
         // Displaying the stack
        printStack(s);
        System.out.println();

        int stocks[]= {100,80,60,70,60,85,100};
        int span[]= new int[stocks.length];
        calculateSpan(stocks,span);

        for(int i=0;i<span.length;i++){
            System.out.print(span[i]+" ");
        }System.out.println();

        int arr[]= {6,8,0,1,3};
        int nxtgreater[]= new int [arr.length];
        NGE(arr, arr.length);

        for(int i=0; i<arr.length; i++){
            System.out.print(nxtgreater[i]+" ");
        }System.out.println();

        String ch="{({})[[]]}";
        System.out.println(isValid(ch));

        System.out.println("hello");
    }
}