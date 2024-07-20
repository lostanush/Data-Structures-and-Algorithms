import java.util.Scanner;

class Node {
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
class  LinkedList {
    Node head;
    Node tail;
    int size;

    public LinkedList() {
        this.head = null;
        this.tail = null;
        this.size = 0;
    }
    public void add(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
            tail = newNode;
        } else {
            tail.next = newNode;
            tail = newNode;
        }
        size++;
    }
    public void addFirst(int data){
        Node newNode = new Node(data);
        newNode.next = head;
        head= newNode;
        size++;
    }
    public void addLast(int data){
        Node newNode = new Node(data);
        tail.next= newNode;
        tail= newNode;
        size++;
    }
    public void add(int idx,int data){
        if(idx==0){
            addFirst(data);
            return;
        }
        Node newNode= new Node(data);
        Node ptr= head;
        idx--;
        
        while(idx!=0){
            idx--;
            ptr=ptr.next;
        }
        newNode.next =ptr.next;
        ptr.next= newNode;
        size++;
    }
    public int rmvFirst(){
        int val= head.data;
        head=head.next;
        size--;
        return val;
    }
    public int rmv(){
        int val= tail.data;
        Node prev= head;
        //while (ptr.next!=tail) {
        //    ptr= ptr.next;
        //}
        for(int i=0;i<size-2;i++){
            prev=prev.next;
        }
        prev.next=null;
        tail=prev;
        size--;
        return val;
    }
    public void rmvIdx(int idx){
        if(idx==0){
            rmvFirst();
            return;
        }
        else {
            if (idx == size-1){
                rmv();
                return;
            }
            else {
                Node ptr= head;
                idx--;
        
                while(idx!=0){
                    idx--;
                    ptr=ptr.next;
                }
                ptr.next=ptr.next.next;
                //ptr.next= newNode;
                size--;
            }
        }        //Node newNode= new Node(data);
        
    }
    public void display() {
        Node current = head;
        while (current != null) {
            System.out.print(current.data + " -> ");
            current = current.next;
        }
        System.out.println("null");
    }

    public int getSize() {
        return size;
    }
}

public class Linkedlist {
    public static void main(String[] args) {
        LinkedList ll =new LinkedList();
        
        System.out.print(" MenuDriven LinkedList Program::");
        System.out.print("\n __\n");
        
        while(true){
            System.out.print("\n Menu::\n");
            System.out.println(" 1. add       4. rmv       7. view");
            System.out.println(" 2. addFirst  5. rmvFirst  8. size");
            System.out.println(" 3. addIdx    6. rmvIdx   ");
            System.out.print(" Select option = ");
            @SuppressWarnings("resource")
            Scanner sc = new Scanner(System.in);
                int ch;
                ch= sc.nextInt();
                System.out.println();

                switch(ch){
   
                    case 1: {  
                        System.out.print("  Enter the [0th]idx element : ");
                        ll.add(sc.nextInt());        
                        System.out.println("   Element added Successfully !!");
                        break;
                    }
                    
                    case 2: {
                        System.out.print("  Enter the [0th]idx element : ");
                        ll.addFirst(sc.nextInt());
                        System.out.println("   Element added Successfully !! ");
                        break;
                    }

                    
                   
                    // case 6: { 
                        
                        
                    //     int idx;
                    //     System.out.print(" Enter the idx : ");
                    //     idx= sc.nextInt();
                    //     if(idx>=ll.size || idx<0){
                    //         System.out.println("  Invalid index !!");
                    //         break;
                    //     }
                    //     else { 
                    //         System.out.print("  Enter the ["+ idx +"th]idx element : ");
                    //         ll.add(idx);
                    //     System.out.println("   Element added Successfully !! ");
                        
                    //     } break;
                    // }
                    case 3: 
                        //if(head!=null){
                            ll.display();
                        //}
                        //else
                        //    System.out.println("Linked List not created !! ");
                        break;

                    // case 8: System.out.println("Size of the list: " + ll.getSize()); break;

                    default: {
                        System.out.println(" Invalid option selected !!");
                        break;
                    }
                }
                } 
    }
}
