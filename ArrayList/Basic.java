/*
swap1() swap2() sort() maxElement() reverse() 
*/
package ArrayList;
import java.util.ArrayList;
import java.util.Collections;

public class Basic {
    
    static void swap1(ArrayList <Integer>list, int idx1,int idx2){
        int temp=list.get(idx1);
        list.set(idx1, list.get(idx2));
        list.set(idx2, temp);
        return;
    }
    static<T> void swap2(ArrayList<T> arr,int i, int j){
        Collections.swap(arr,i,j);
        return;
    }
    static void sort(ArrayList<Integer> list){
        Collections.sort(list); //for descending -> Collections.sort(list, Collections.reverseOrder());
        return;
    }
    static int maxElement(ArrayList<Integer>list){
        int max= Integer.MIN_VALUE;
        for(int i=0;i<list.size();i++){
            max= Math.max(max,list.get(i));
        }
        return max;
    }
    static<T> void reverse(ArrayList<T> list){
        Collections.reverse(list);
    }

    public static void main(String[] args) {
        ArrayList<Integer> arr= new ArrayList<>();
        arr.add(0);
        arr.add(1);
        arr.add(2);
        System.out.println("array add(3): "+ arr);
        arr.remove(2);
        System.out.println("rmv 2nd idx : "+ arr);
        arr.set(0,3);
        System.out.println("set 0th-> 10: "+ arr);
        System.out.println("");
        
        System.out.println("Before swap: " + arr);
        swap1(arr, 0, 1);
        System.out.println("After swap1: " + arr);        
        swap2(arr, 0, 1);
        System.out.println("After swap2: " + arr); 
        sort(arr);
        System.out.println("After sort : " + arr);  
        System.out.println("");
        
        ArrayList<Integer> list1 = new ArrayList<>();
        list1.add(1);
        list1.add(2);
        list1.add(3);
        ArrayList<Integer>list2 = new ArrayList<>();
        list2.add(4);
        list2.add(5);
        
        ArrayList <ArrayList<Integer>> mainlist= new ArrayList<>(); 
        mainlist.add(list1);
        mainlist.add(list2);

        System.out.println("list1: "+ list1);
        System.out.println("list2: "+ list2);
        System.out.println("list1+list2: "+ mainlist);
        System.out.println("");
        
        reverse(list1);
        System.out.println("list1 reverse : " + list1);
        System.out.println("list1 MaxElement: " + maxElement(list1));
        
        swap2(mainlist,0,1);
        System.out.println("mainlist swap2  : " + mainlist);
        
    }
}