// QUESTION (01)
import java.util.ArrayList;

class ContainerWithMostWater {
    
    static void MaxWater(ArrayList<Integer> list){
        int maxwater=0;
        int lp=0;
        int rp=list.size()-1;
        
        while(lp<rp){   
            int ht = Math.min(list.get(lp),list.get(rp));
            int width= rp-lp;
            int curr = ht* width;
            maxwater= Math.max(curr,maxwater);
            if(list.get(lp)<list.get(rp)){
                lp++;
            }
            else rp--;
        }
        System.out.println("Maximum Water Contained will be "+ maxwater+ "unit.sq !! ");
    }

    public static void main(String[] args) {
        System.out.println("Hello World !!");
        //1,8,6,2,5,4,8,3,7;
        int[] arr = {1, 8, 6, 2, 5, 4, 8, 3, 7};
        ArrayList<Integer> height = new ArrayList<>();
        for(int i: arr){
            height.add(i);
        }
        MaxWater(height);
 
    }
}

// Container With Most Water !! Flipkart ,+1 ;
    /* For a given n lines on x axis, use 2 lines to from a container such that it holds maximum water. */
    
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


        /*
         * 
         * # Array Questions

Sure! Here's an arrangement of the questions based on difficulty levels—Easy, Medium, and Hard—separately for each set.

## Initial Set of Questions

### Easy
- **268.** Missing Number
- **26.** Remove Duplicates from Sorted Array
- Find the Largest and Smallest Numbers
  - Example: Find the largest and smallest numbers in an array.

### Medium
- **287.** Find the Duplicate Number
- **189.** Rotate Array
- **88.** Merge Sorted Array
- **349.** Intersection of Two Arrays

### Hard
- **560.** Subarray Sum Equals K
- **53.** Maximum Subarray (Kadane's Algorithm)
- **238.** Product of Array Except Self

## Additional Set of Questions

### Easy
- **1.** Two Sum
- **442.** Find All Duplicates in an Array
- **169.** Majority Element
- **162.** Find Peak Element

### Medium
- **11.** Container With Most Water
- **121.** Best Time to Buy and Sell Stock
- **152.** Maximum Product Subarray
- **128.** Longest Consecutive Sequence
- **713.** Subarray Product Less Than K
- **73.** Set Matrix Zeroes
- **15.** 3Sum

### Hard
- **18.** 4Sum
- **4.** Median of Two Sorted Arrays
- **54.** Spiral Matrix

## Summary

By working through these problems, starting from the easy ones and progressing to the harder ones, you'll build a solid foundation and gradually increase your problem-solving skills. This approach will help you tackle array-based questions more effectively in interviews.

         */