//linked list code - written on 4th sem @anushdighore 
//add 3 - addFirst,addLast,add;
//remove 3 - removeFirst,removeLast,remove

import java.util.Scanner;
public class LinkedlistQue {

    // Ading node ------------------------------------->
   // Removing node ------------------------------------->

 

   
    

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
               
    }
}
