import java.util.LinkedList;
public class LinkedlistQue {

    public static void main(String []args){
        LinkedList<Integer> ll= new LinkedList<>();
        ll.add(1);
        ll.add(2);
        ll.add(3);
        ll.add(4);
        ll.add(5);
        ll.addFirst(0);
        System.out.println(ll);
    }
}
