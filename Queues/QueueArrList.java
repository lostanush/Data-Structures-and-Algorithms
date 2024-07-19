import java.util.ArrayList;

class Queue{
    
    static ArrayList<Integer> list = new ArrayList<>();
    public static boolean isEmpty(){
        return list.size() == 0;
    }

    //enqueue
    public void enqueue(int data){
        list.add(data);
    }

    //dequeue
    public int dequeue(){
        int front= list.get(0);
        list.remove(0);
        return front;
    }

    //peek
    public int peek(){
        return list.get(0);
    }
    
    //display
    public void display(){
        System.out.println(list);
    }
}

public class QueueArrList {
    public static void main(String[] args){
        Queue q =new Queue();
        q.enqueue(0);
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        q.display();
        q.dequeue();
        q.dequeue();
        q.display();
    }
}
