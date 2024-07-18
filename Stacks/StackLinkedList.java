import java.util.*;

class Stack {
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
    private Node top = null;

    // Method to push an element onto the stack
    public void push(int data) {
        Node newNode = new Node(data, top);
        top = newNode;
    }

    // Method to display the stack elements
    public void display() {
        Node ptr = top;
        System.out.println("Stack-LinkedList:");
        while (ptr != null) {
            System.out.print(" " + ptr.data);
            ptr = ptr.next;
        }
        System.out.println();
    }
}

public class StackLinkedList {
    public static void main(String[] args) {
        Stack s = new Stack();

        // Adding nodes to the stack
        s.push(10);
        s.push(20);
        s.push(30);

        // Displaying the stack
        s.display();
    }
}
