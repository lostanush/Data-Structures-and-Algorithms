//import java.util.*;

// Stack implementation
class Queue {
    // Nested Node class
    static class Node {
        int data;
        Node next;

        Node() {}

        Node(int data) { 
            this.data = data; 
            this.next = null;    
        }

        Node(int data, Node next) { 
            this.data = data; 
            this.next = next; 
        }
    }

    // Reference to the top of the stack
    private Node front = null;

    // Method to push an element onto the stack
    public void enqueue(int data) {
        Node newNode = new Node(data);
        Node ptr=front;
        if(ptr!=null){
            while (ptr.next!=null) {
                ptr=ptr.next;
            }
            ptr.next= newNode;
        }
        else front=newNode;
        
        
    }

    //
    public int dequeue(){
        int val= front.data;
        front=front.next;
        return val;
    }

    // Method to display the stack elements
    public void display() {
        Node ptr = front;
        System.out.println("Stack-LinkedList:");
        while (ptr != null) {
            System.out.print(ptr.data+" ");
            ptr = ptr.next;
        }
        System.out.println();
    }
}

public class QueueLL {
    public static void main(String[] args) {
        Queue s = new Queue();

        // Adding nodes to the stack
        s.enqueue(10);
        s.enqueue(20);
        s.enqueue(30);

        s.dequeue();
        // Displaying the stack
        s.display();
    }
}