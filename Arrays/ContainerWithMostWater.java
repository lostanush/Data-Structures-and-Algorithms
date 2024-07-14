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