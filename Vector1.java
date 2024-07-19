/**
 * Vector
 */
import java.util.*;

public class Vector1 {
    public static class InnerVector1 {
        int a;
        public InnerVector1(int a){
            this.a=a;    
        }
        public InnerVector1(){
            a= 10;
        }
        public void show(){
            System.out.println(a);
        }    
        
    }

    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            Vector<Integer> arr = new Vector<Integer>();

            for (int i = 0; i < 5; i++) {
                arr.add(sc.nextInt());
            }
            for (int i = 0; i < 5; i++) {
                System.out.println(arr.get(i));
            }
        }
        
        //Vector<InnerVector1>= new Vector<InnerVector1>();
        
    }
}