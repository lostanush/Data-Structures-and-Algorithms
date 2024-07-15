//ArrayList : 
/*  .size(); 
    .get(i);
    Collections.sort(list);
    Collections.sort(list, Collections.reverseOrder());
*//*
swap() sort() reverse() maxElement() 
*/    

import java.util.ArrayList;
import java.util.Collections;

public class ArrayListBasic {

    static void swap(ArrayList <Integer>list, int idx1,int idx2){
        int temp=list.get(idx1);
        list.set(idx1, list.get(idx2));
        list.set(idx2, temp);
        System.out.println(list);
    }

    public void sort(ArrayList <Integer>list){
        Collections.sort(list);
        //for descending -> Collections.sort(list, Collections.reverseOrder());
        return;
    }

    static int maxElement(ArrayList<Integer>list){
        int max= Integer.MIN_VALUE;
        for(int i=0;i<list.size();i++){
            max= Math.max(max,list.get(i));
        }
        return max;
    }
   
    static void reverse(ArrayList<Integer> list){

    }

    public static void main(String[] args) {
        System.out.println("Hello World !!");

        ArrayList <ArrayList<Integer>> mainlist= new ArrayList<>();
        
        ArrayList<Integer> list = new ArrayList<>();
        list.add(1);
        list.add(2);
        list.add(4);
        mainlist.add(list);

        ArrayList<Integer>list2 = new ArrayList<>();
        list2.add(3);
        list2.add(4);
        mainlist.add(list2);

        System.out.println("list1: "+list);
        System.out.println("list2: "+list2);
        System.out.println("list1+list2: "+mainlist);
        
        maxElement(list);
        swap(list,0,2);






    }
}

//ArrayList :  
/*  add element -          O(1) , .size(); .get(i);
    Get element  -         O(1)
    remove element -       O(n)
    Set element at Index - O(1)
    Contains element -     O(1)  

    Reverse,Maxelement,swap,sort
    que 1): Container with MOST_WATER;
    que 2): TargetValue- PairSum1
    que 3): TargetValue- PariSum2- sorted & rotated 
*/

