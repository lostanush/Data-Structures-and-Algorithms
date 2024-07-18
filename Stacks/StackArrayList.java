//stacks:

import java.util.ArrayList;

class Stack{
    static ArrayList<Integer> list = new ArrayList<>();
    public static boolean isEmpty(){
        return list.size() == 0;
    }

    //push
    public void push(int data){
        list.add(data);
    }

    //pop
    public int pop(){
        int top= list.get(list.size()-1);
        list.remove(list.size()-1);
        return top;
    }

    //peep
    //peak
    public int peak(){
        return list.get(list.size()-1);
    }        
}

public class StackArrayList {
    public static void main(String[] args) {
        Stack s =new Stack();
        s.push(0);
        s.push(1);
        s.push(2);

        System.out.println("Hello : "+s.pop());
    }
}