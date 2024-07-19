//import java.util.*;

class Stu{
    public int roll;
    public String name;
    public Stu(){
        roll=0;
        name="";
    }
    public Stu(int r,String n){
        roll=r;
        name=n;
    }
    public int getroll(){ 
        return roll;
    }
    public String getname(){ 
        return name;
    }
    public void setroll(int r){
        this.roll=r; 
    }
    public void setname(String n){
        this.name=n; 
    }
    public void display(){
        System.out.println(this.roll+this.name);
    }

}

public class Student {
    public static void main(String[] args){
        System.out.println("HEll\\o");
        Stu anush=new Stu();
        anush.setname("AnushDighore");
        anush.setroll(28);
        anush.display();

        Stu ayush =new Stu();
        ayush.name="AyushDighore";
        ayush.roll=21;
        ayush.display();

        Stu rekha =new Stu(2,"RekhaDighore");
        rekha.display();

    }
}
