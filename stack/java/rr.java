import java.util.*;
public class rr {
    static void findwaitingtime(int processes[], int n, int bt[], int q,int wt[]) {
        int rem_bt[] = new int[n];
        
        for (int i = 0; i < n; i++) {
            rem_bt[i] = bt[i];
        }

        int t = 0;
        while (true) {
            
            boolean done = true;
            for (int i = 0; i < n; i++) {

                if (rem_bt[i] > 0) {
                    done = false;
                    if (rem_bt[i] > q) {
                        
                        rem_bt[i] -= q;
                        t = t + q;
                    } else {
                        t = t + rem_bt[i];
                        wt[i] = t - bt[i];
                        rem_bt[i] = 0;
                    }
                }
            }
            if (done) {
                break;
            }

        }
    }
    static void findtat(int processes[],int n,int bt[],int q,int wt[], int tat[]  ){
    for(int i=0;i<n;i++){
            tat[i] = bt[i]+wt[i];
        }

    }
    
    static void findavgtime(int processes[],int n,int bt[],int q){
            int tat[]=new int[n];
            int wt[]=new int[n];
            int total_tat=0;
            int total_wt=0;
             findwaitingtime(processes, n, bt, q, wt);
            findtat(processes, n, bt, q, wt, tat);
            System.out.println(" Pn "+" BT "+" WT "+" TAT");
            for(int i=0;i<n;i++){
                total_tat+=tat[i];
                total_wt+=wt[i];
                System.out.println(" "+(i+1)+"\t\t"+bt[i]+"\t\t"+wt[i]+"\t\t"+tat[i]);
            }
            System.out.println("avg Turn Around time is "+ total_tat/n);
            System.out.println("avg Waiting time is "+ total_wt/n);

    }
    static void findwaitingt(int processes[], int n, int bt[], int q,int wt[]) {
        int rem_bt[] = new int[n];
        
        for (int i = 0; i < n; i++) {
            rem_bt[i] = bt[i];
        }

        int t = 0;
        while (true) {
            
            boolean done = true;
            for (int i = 0; i < n; i++) {

                if (rem_bt[i] > 0) {
                    done = false;
                    if (rem_bt[i] > q) {
                        
                        rem_bt[i] -= q;
                        t = t + q;
                    } else {
                        
                        t = t + rem_bt[i];
                        wt[i] = t - bt[i];
                        rem_bt[i] = 0;
                    }
                }
            }
            if (done) {
                break;
            }

        }
    }
    static void findt(int processes[],int n,int bt[],int q,int wt[], int tat[]  ){
        for(int i=0;i<n;i++){
                tat[i] = bt[i]+wt[i];
            }
    
        }
    
    static void findavgt(int processes[],int n,int bt[],int q){
        int tat[]=new int[n];
        int wt[]=new int[n];
        int total_tat=0;
        int total_wt=0;
         findwaitingt(processes, n, bt, q, wt);
        findt(processes, n, bt, q, wt, tat);
        System.out.println(" Pn "+" BT "+" WT "+" TAT");
        for(int i=0;i<n;i++){
            total_tat+=tat[i];
            total_wt+=wt[i];
            System.out.println(" "+(i+1)+"\t\t"+bt[i]+"\t\t"+wt[i]+"\t\t"+tat[i]);
        }
        System.out.println("avg Turn Around time is "+ total_tat/n);
        System.out.println("avg Waiting time is "+ total_wt/n);

}
    public static void main(String args[]) {
        int processes[] = { 1, 2, 3 };
        int n = 3;
        int q = 2;
        int bt[] = { 10, 5, 8 };
        
      
        findavgtime(processes, n, bt, q);
        
        // else if (choice==2){
        //     findavgt(processes, n, bt, q);
        // }
    }
}