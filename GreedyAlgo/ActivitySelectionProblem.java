import java.util.Scanner;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Collections;

public class ActivitySelectionProblem{
    public static void main(String[] args) {
        System.out.println("Hello");
        int start[]={1,3,0,5,8,5};
        int end[]= {2,4,6,7,9,9} ;

        int activities[][] = new int[start.length][3];
        for (int i=0; i<start.length; i++){
            activities[i][0] = i;
            activities[i][1] = start[i] ;
            activities[i][2] = end[i] ;
        }
        Arrays.sort(activities,Comparator.comparingDouble(a -> a[2]));

        maxAct = 1;
        ans.add(0);
        int lastEnd = end[0];
        for(int i=0; i<end.length; i++){
            if(start[i] >= lastEnd)
        }


        // Scanner sc = new Scanner(System.in);
        // int n = sc.nextInt();

        // List<int[]> intervals = new ArrayList<>();
        // for(int i=0; i<n;i++){
        //     int start = sc.nextInt();
        //     int end = sc.nextInt();
        //     intervals.add(new int[]{start,end});
        // }
        //Collections.sort(intervals,Comparator.comparingInt(a->a[1]));
        
        // lambda function -> shortform :
        

        int take=0;
        int lastEnd =-1;

        for(int[] interval : intervals){
            if(interval[0]>=lastEnd){
                take++;
                lastEnd = interval[1];
            }
        }
        System.out.println(take);
        sc.close();
    

        // int n; cin>>n;
        // vector<vector<int>> v;
        // for(int i=0; i<n; i++){
        //     int start, end;
        //     cin>>start>>end;
        //     v.push_back({start,end});
        // }
        // sort(v.begin(),v.end(),[&](vector<int> &a, vector<int> &b){
        //     return a[1]<b[1];
        // })
        // int take =1;
        // int end = v[0][1];
        // for(int i=0; i<n;i++){
        //     if(v[i][0]>=end){
        //         take++;
        //         end= v[i][1];
        //     }
        // }
        // cout<<take<<"\n";


    }
}