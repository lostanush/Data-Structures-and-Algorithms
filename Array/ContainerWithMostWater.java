import java.util.ArrayList;

public class ContainerWithMostWater {
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

    public static void main(String[] args) {
        System.out.println("Hello World !!");
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
 
    }
}
