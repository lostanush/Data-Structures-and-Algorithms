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

    public static void main (String args[]){
        
        int[] arr = {1,2,3,4,5,6};
        ArrayList<Integer> nums =new ArrayList<>();
        for(int i: arr){
            nums.add(i);
        }
        System.out.println(twoSum(nums, 6));
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