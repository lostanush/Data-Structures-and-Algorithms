import java.util.Scanner;

class Student {
     int roll;
     String name;
    public Student(int r,String n){
        this.roll= r;
        this.name= n;
    }
}
class Exam extends Student {
    int phy,chem,math,cs,eng;
    public Exam (int r,String n){
        super(r,n);
    }
    public void read(){
        System.out.println("total= ");
        try (Scanner sc = new Scanner(System.in)) {
            phy = sc.nextInt();
            chem= sc.nextInt();
            math= sc.nextInt();
            cs  = sc.nextInt();
            eng = sc.nextInt();
        }
        
    }
}
class Result extends Exam {
    public int total;
    public int percent;
    public Result (int r,String n){
        super(r,n);
    }
    public void caltot(){
        total  = phy+ chem+ math + cs+ eng ;
    }
    public void per(){
        System.out.println("total= "+total+"\n Percentage= "+total/6);
    }

}


public class miniproject1 {
    public static void main (String []args ){
        Result A= new Result(100,"AnushDighore");
        A.read();
        A.caltot();
        A.per();
    }
}
