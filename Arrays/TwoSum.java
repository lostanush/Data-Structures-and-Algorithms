import java.util.ArrayList;
import java.util.Collections;

public class TwoSum {
    public static boolean twoSum(ArrayList <Integer>list,int target){
        Collections.sort(list);
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
    public static boolean twoSum2(ArrayList <Integer>list,int target){
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


    public static void main (String args[]){
        
        int[] nums = {1,2,3,4,5,6};
        ArrayList<Integer> arr =new ArrayList<>();
        for(int i: nums){
            arr.add(i);
        }
        System.out.println(twoSum(arr, 6));
        
        // 11,12,6,7,8,9,10 - Sorted & Rotated
        int[] nums2= {11,12,6,8,9,10};
        ArrayList<Integer> arr2 =new ArrayList<>();
        for(int i : nums2){
            arr2.add(i);
        }
        System.out.println(twoSum2(arr2, 20));
    }
}


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