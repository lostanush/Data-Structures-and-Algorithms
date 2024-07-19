//linked list code - written on 4th sem @anushdighore 
//add 3 - addFirst,addLast,add;
//remove 3 - removeFirst,removeLast,remove
//reverse ll
//check palindrome
//check iscycle : Floyd's CFA 
//MergeSOrt
//convert into zigzag ll 1-> n-> 2-(n-1)....mid

import java.util.Scanner;
public class Linkedlist {
    
    public static class Node {
        int data;
        Node next;
        Node() {}
        Node(int data) { 
            this.data = data; 
            this.next= null;    
        }
        Node(int data, Node next) { 
            this.data = data; 
            this.next = next; 
        }
        
    }
    public static Node head;
    public static Node tail;
    public static int size;

    // Adding node ------------------------------------->

    public void create(int data){
        Node newNode = new Node(data);
        head= tail = newNode;
        size++;
    }
    public void display(){
        Node ptr= head;
        System.out.println(" LinkedList :");
        while (ptr!=null) {
            System.out.print(" "+ptr.data);
            ptr= ptr.next;
        }
        System.out.println();
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

    // Removing node ------------------------------------->

    public int removeFirst(){
        int val= head.data;
        head=head.next;
        size--;
        return val;
    }

    public int removeLast(){
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
    public void remove(int idx){
        if(idx==0){
            removeFirst();
            return;
        }
        //Node newNode= new Node(data);
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

    // Reversing node ------------------------------------->

    public void rev(){
        Node prev= null;
        Node curr= tail= head;
        Node next ;

        while (curr!=null){
            next= curr.next;
            curr.next= prev;
            prev= curr;
            curr= next;
        }
        head= prev;
    }

    //Delete Nth from Ending ------------------------------->
    public void DelNthFromEnd(int n){
        Node prev= head;
        //System.out.println(head.data);
        // size-n+1 the node to be deleterd !! 
        /* 
        int sz= size;
        int i=1;
        int itoFind = sz-n;
        while (i<itoFind) {
            prev=prev.next;
            i++;            
        }
        prev.next= prev.next.next;
        return;
        */
        if(n== size){
            removeFirst();
            return;
        }else if(n>size || n<1){
            System.out.println("INvalid index !! ");
            return;
        }
        int sz= size;
        int prevv = sz-n-1;
        System.out.println("Deleting "+(prevv+2)+"th Node : ");
        while (prevv!=0) {
            prev=prev.next;
            prevv--;            
        }
        prev.next= prev.next.next;
        return;
        
    }

    public static Node mid(Node head) {
        if (head == null || head.next == null) {
            return head;
        }
    
        Node slow = head;
        Node fast = head.next;
    
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
    
        return slow;
    }

    // check if Palindrome------------------------------------->
    public boolean checkPalindrome(){
        if(head == null || head.next == null){
            return true;
        }
        // step1 : Find Mid;
        Node mid= mid(head);

        // step2 : Reverse 2nd Half;
        Node prev= null;
        Node curr= mid;
        Node next ;

        while (curr!=null){
            next= curr.next;
            curr.next= prev;
            prev= curr;
            curr= next;
        }
        // step3 : check Palindrome;
        Node left=head;
        Node right=prev;

        while(right!=null){
            if(left.data!=right.data){
                return false;
            }
            left= left.next;
            right= right.next;
        }
        return true;
    } 

    //check cycle============  Floyd's CFA
    public static boolean iscycle(){
        Node slow= head;
        Node fast= head;

        while(fast!=null && fast.next != null){
            slow= slow.next;
            fast= fast.next.next;
            if (slow==fast)
                return true;
        }
        return false;
    }
    public static void removecylel(){
        if(Linkedlist.iscycle()){
            Node slow =head;
            Node fast= head;
            Node prev= head;
            
            while(slow!=fast){
                prev=fast;
                slow=slow.next;
                fast=fast.next.next;
            }
            prev.next=null;
        }
    }

    /////////////////////////////////////////////////
    // MergeSort==============================

    public static Node merge(Node head1, Node head2) {
        Node mergedLL = new Node(-1);
        Node temp = mergedLL;
    
        while (head1 != null && head2 != null) {
            if (head1.data <= head2.data) {
                temp.next = head1;
                head1 = head1.next;
            } else {
                temp.next = head2;
                head2 = head2.next;
            }
            temp = temp.next;
        }
    
        // Add remaining elements from either list
        if (head1 != null) {
            temp.next = head1;
        }
        if (head2 != null) {
            temp.next = head2;
        }
    
        return mergedLL.next;
    }

    public static Node mergeSort(Node head) {
        if (head == null || head.next == null)
            return head;
    
        // Find the middle of the list
        Node mid = mid(head);
        Node rightHead = mid.next;
        var leftHead = head;
        mid.next = null; // Splitting the list into two halves
    
        // Recursively sort the two halves
        Node newLeft = mergeSort(leftHead);
        Node newRight = mergeSort(rightHead);
    
        // Merge the sorted halves
        return merge(newLeft, newRight);
    }

    public static Node rev(Node mid){
        Node curr=mid.next;
        mid.next=null;
        
        Node next;
        Node prev= null;

        while (curr!=null){
            next= curr.next;
            curr.next= prev;
            prev= curr;
            curr= next;
        }
        return prev;
    }

    public static Node zigzag(){
        // FInd mid;
        // reverse second half 
        // merge (alternate adding)
        Node zigzag= new Node();
        zigzag.next= null;

        Node mid = mid(head);
        Node right= rev(mid);
        Node left = head;
        Node nextL;
        Node nextR;

        while(left!=null && right!=null){
            nextL=left.next;
            nextR=right.next;
            left.next=right;
            right.next=nextL;

            left=nextL;
            right=nextR;
        }
        return head;
    }




    public static void main(String[] args) {
        Linkedlist ll =new Linkedlist();
        
        int ch;
        
        System.out.print(" MenuDriven LinkedList Program::");
        System.out.print("\n __\n");
    
    
        while(true){
            System.out.print("\n Menu::\n");
            System.out.println(" 1. Create       2. View ");
            System.out.println(" 4. addFirst     5. addLast     6. addIdx");
            System.out.println(" 7. removeFirst  8. removeLast  9. removeIdx");
            System.out.print(" Select option = ");
            try (Scanner sc = new Scanner(System.in)) {
                ch= sc.nextInt();
                
                System.out.println();

                switch(ch){
   
                    case 1: {
                        if(head==null){
                            System.out.print("  Enter the [0th]idx element : ");
                            //data=sc.nextInt();
                            ll.create(sc.nextInt());        
                            System.out.println("   Element added Successfully !!");
                        }
                        else 
                            System.out.println(" LL is already created !!");
                        break;
                    }
                    
                    case 2: {
                        if(head!=null){
                            ll.display();
                        }
                        else
                            System.out.println("Linked List not created !! ");
                        break;
                    }

                    case 3: {

                    }

                    case 4: {
                        System.out.print("  Enter the [0th]idx element : ");
                        ll.addFirst(sc.nextInt());
                        System.out.println("   Element added Successfully !! ");
                        break;
                    }

                    case 5: {
                        System.out.print("  Enter the ["+ size +"th]idx element : ");
                        ll.addLast(sc.nextInt());
                        System.out.println("   Element added Successfully !! ");
                        break;
                    }

                    case 6: {
                        int idx;
                        System.out.print(" Enter the idx : ");
                        idx= sc.nextInt();
                        if(idx>=size || idx<0){
                            System.out.println("  Invalid index !!");
                            break;
                        }
                        System.out.print("  Enter the ["+ idx +"th]idx element : ");
                        if(idx==0)
                            ll.addFirst(sc.nextInt());
                        else if(idx==size-1)
                            ll.addLast(sc.nextInt());
                        else
                            ll.add(idx, sc.nextInt());
                        System.out.println("   Element added Successfully !! ");
                        break;
                    }
                    
                    default: {
                        System.out.println(" Invalid option selected !!");
                        break;
                    }
                }
            }
        }        
    }
}