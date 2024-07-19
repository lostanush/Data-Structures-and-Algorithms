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

 import java.util.ArrayList;
 import java.util.Collections;

 public class ArraylistQue {

    public void reverse(ArrayList<Integer> list){

    }
    public static void maxelement(ArrayList<Integer>list){
        int max= Integer.MIN_VALUE;
        for(int i=0;i<list.size();i++){
            max= Math.max(max,list.get(i));
        }
        System.out.println(max);
    }
    public static void swap (ArrayList <Integer>list, int idx1,int idx2){
        int temp=list.get(idx1);
        list.set(idx1, list.get(idx2));
        list.set(idx2, temp);
        System.out.println(list);
    }
    public void sort (ArrayList <Integer>list){
        Collections.sort(list);
        //for descending -> Collections.sort(list, Collections.reverseOrder());
        return;
    }

    // QUESTION (01)
    // Container With Most Water !! Flipkart ,+1 ;
    /* For a given n lines on x axis, use 2 lines to from a container such that it holds maximum water. */
    public static void ContainerWithMaxWater(ArrayList<Integer> list){
        int counter=0;
        //METHOD 1 :
        /*int maxwater= Integer.MIN_VALUE;
        for(int i=0;i<list.size();i++){
            for(int j=0;j<list.size();j++){
                int ht= Math.min(list.get(i),list.get(j));
                int width= j-i;
                int currWater= ht*width;
                maxwater= Math.max(currWater,maxwater);
                counter++;
            }
        }*/

        //METHOD :
        int maxwater=0;
        int lp=0;
        int rp=list.size()-1;
        while(lp<rp){   
            int ht = Math.min(list.get(lp),list.get(rp));
            int width= rp-lp;
            int currWater = ht* width;
            maxwater= Math.max(currWater,maxwater);
            if(list.get(lp)<list.get(rp)){
                lp++;
            }
            else rp--;
            counter++;
        }
        System.out.println("Maximum Water Contained will be "+ maxwater+ "unit.sq !! "+ counter);
    }
    
    public static boolean pairsum1(ArrayList <Integer>list,int target){
        Collections.sort(list);
        //Method 1 : Bruteforce 
        /* 
        for(int i=0;i<list.size();i++){
            for(int j=0;j<list.size();j++){
                if(list.get(i)+list.get(j)==target)
                    return true;
                else return false;
            }
        }
        */
        // Method 2: 2 pointer approch
        int lp=0;
        int rp=list.size()-1;
        
        while (lp < rp) {
            int sum = list.get(lp) + list.get(rp);
            
            // Case 1:
            if (sum == target) {
                //System.out.println("Found!!");
                return true;
            } else if (sum < target) {  // Case 2:
                lp++; // Move the left pointer to the right to increase the sum
            } else {  // Case 3: 
                rp--; // Move the right pointer to the left to decrease the sum
            }
        }
        return false;
        
    }

    // Method : 2 pointer approch
    public static boolean pairsum2(ArrayList <Integer>list,int target){
        int bp=0; //breaking point
        for(int i=0;i<list.size();i++){
            if(list.get(i)>list.get(i)){
                bp= i;
                break;
            }
        }
        int lp= bp+1; //smallest
        int rp= bp;

        while (lp != rp) {
            int sum = list.get(lp) + list.get(rp);
            int n = list.size();

            // Case 1:
            if (sum == target) {
                //System.out.println("Found!!");
                return true;
            } 
            //case 2:
            if (sum < target) {  
                lp= (lp+1)%list.size();                // Move the left pointer to the right to increase the sum
            } else {  
                // Case 3: 
                rp= (n+rp-1)%n;                                 // Move the right pointer to the left to decrease the sum
            }
        }
        return false;
        
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

        System.out.println(list);
        System.out.println(list2);
        System.out.println(mainlist);
        maxelement(list);
        swap(list,0,2);

        //1,8,6,2,5,4,8,3,7;
        ArrayList<Integer> height = new ArrayList<>();
        height.add(1);
        height.add(8);
        height.add(6);
        height.add(2);
        height.add(5);
        height.add(4);
        height.add(8);
        height.add(3);
        height.add(7);
        ContainerWithMaxWater(height);

        ArrayList<Integer> pair1 =new ArrayList<>();
        pair1.add(1);
        pair1.add(2);
        pair1.add(3);
        pair1.add(4);
        pair1.add(5);
        pair1.add(6);
        System.out.println(pairsum1(pair1, 6));

        ArrayList<Integer> pair2 =new ArrayList<>();
        // 11,12,6,7,8,9,10 - Sorted & Rotated
        pair2.add(11);
        pair2.add(12);
        pair2.add(6);
        pair2.add(8);
        pair2.add(9);
        pair2.add(10);
        System.out.println(pairsum2(pair2, 20));

    }
}
