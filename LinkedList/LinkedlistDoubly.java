//linked list code - written on 4th sem @anushdighore 
//add 3 - addFirst,addLast,add;
//remove 3 - removeFirst,removeLast,remove

public class LinkedlistDoubly {

    public static class Node {
        int data;
        Node next;
        Node prev;
        Node() {}
        Node(int data) { 
            this.data = data; 
            this.next= null;
            this.prev= null;    
        }
        Node(int data, Node next, Node prev) { 
            this.data = data; 
            this.next = next;
            this.prev = prev; 
        }
        public void create() {
            // TODO Auto-generated method stub
            throw new UnsupportedOperationException("Unimplemented method 'create'");
        }
    }
    public static Node head;
    public static Node tail;
    public static int size;

    public void create(int data){
        Node newNode = new Node(data);
        head= tail = newNode;
        size++;
    }
    public void display(){
        Node ptr= tail;
        System.out.println();
        System.out.print("DoublyLinkedList :");
        while (ptr!=null) {
            System.out.print(" "+ptr.data);
            ptr= ptr.prev;
        }
    }
    
    public void addFirst(int data){
        Node newNode = new Node(data);
        newNode.next = head;
        head.prev = newNode;
        head= newNode;
        size++;
    }
    
    public void addLast(int data){
        Node newNode = new Node(data);
        newNode.prev = tail;
        tail.next = newNode;
        tail = newNode;
        size++;
    }

    public void add(int idx,int data){
        if(idx==0){
            addFirst(data);
            return;
        }
        Node newNode= new Node(data);
        Node ptrprev= head;
        idx--;
        
        while(idx!=0){
            idx--;
            ptrprev=ptrprev.next;
        }
        newNode.next = ptrprev.next;
        newNode.prev = ptrprev;
        ptrprev.next.prev= newNode; 
        ptrprev.next = newNode;
        size++;
    }

    public int removeFirst(){
        int val= head.data;
        head.next.prev=null;
        head=head.next;
        size--;
        return val;
    }

    public int removeLast(){
        int val= tail.data;
        //Node ptrprev= head;
        //while (ptr.next!=tail) {
        //    ptr= ptr.next;
        //}
        //for(int i=0;i<size-2;i++){
        //    ptrprev=ptrprev.next;
        //}
        //ptrprev.next=null;
        //tail=prev;
        
        tail= tail.prev;
        tail.next= null;
        size--;
        return val;
    }
    public void remove(int idx){
        if(idx==0){
            removeFirst();
            return;
        }
        //Node newNode= new Node(data);
        Node ptrprev= head;
        idx--;
        
        while(idx!=0){
            idx--;
            ptrprev=ptrprev.next;
        }
        ptrprev.next.next.prev=ptrprev;
        ptrprev.next= ptrprev.next.next;
        size--;
    }

    public static void rev(){
        Node curr=head;
        Node prev=null;
        Node next;
        tail=head;

        while(curr!=null){
            next= curr.next;
            curr.next=prev;
            curr.prev=next;
            prev=curr;
            curr=next;
        }
        head=prev;

    }

    public static void main(String[] args) {
        //incomplete code ..............
        LinkedlistDoubly ll =new LinkedlistDoubly();
        //Node ll1= new Node();
        //ll1.create();
        ll.create(3);
        ll.addFirst(1);
        ll.addLast(4);
        ll.addLast(5);
        ll.addLast(6);
        ll.addLast(7);
        ll.add(1,2);
        ll.removeFirst();
        ll.removeLast();        
        ll.display();

        ll.remove(1);
        ll.display();
        
        LinkedlistDoubly.rev();
        ll.display();
        //head.display();     
    }
}
