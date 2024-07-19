//import java.util.ArrayList;

class Queue{
    static int arr[];
    static int n;
    static int size;
    static int front;
    static int rear;

    public Queue(int n){
        arr= new int[n];
        size=n;
        rear= front=-1;
    }
    
    //enqueue
    public void enqueue(int data){
        if(rear==size-1){
            System.out.println("Array is full ! ");
            return;
        }
        rear=rear+1;
        arr[rear]=data;
        n++;
    }

    //dequeue
    public int dequeue(){
        int val= arr[0];
        for(int i=0;i<n; i++){
            arr[i]=arr[i+1];
        }
        n--;
        return val;   
    }

    //peek
    public int peek(){
        return arr[front];
    }

    //display
    public void display(){
        for(int i=0; i<n; i++){
            System.out.print(arr[i]+" ");
        }
    }
}

public class QueueArr {
    public static void main(String[] args){
        Queue q =new Queue(10);
        q.enqueue(0);
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        q.dequeue();
        q.enqueue(9);
        q.display();
        //q.dequeue();
        //q.dequeue();
        //q.display();
    }
}
