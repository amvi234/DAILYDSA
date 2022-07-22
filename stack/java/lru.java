import java.util.*;
public class lru {
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter 1 for fifo press 2 for lru");
        int choice=sc.nextInt();
        int n;
        System.out.println("Enter the content of pages: ");
        n=sc.nextInt();
        int pf=0;
        if(choice==1){
            ArrayDeque<Integer>DQ = new ArrayDeque<Integer>(3);
            for(int i=0;i<n;i++){
                int ele = sc.nextInt();
                if(DQ.size()<3 && !DQ.contains(ele) ){
                    DQ.add(ele);
                    pf++;
                }
                else if(!DQ.contains(ele)){
                    DQ.removeFirst();
                    DQ.add(ele);
                    pf++;
                }
                System.out.println(DQ);
            }
        }
        else{
            ArrayList<Integer>AL=new ArrayList<Integer>();
            HashMap<Integer,Integer>HM = new HashMap<>();
            new HashMap<Integer,Integer>();
            for(int i=0;i<n;i++){
                int ele = sc.nextInt();
                if(AL.size()<3  && !AL.contains(ele)){
                    AL.add(ele);
                    pf++;
                }
                else if(!AL.contains(ele)){
                    int index=0;
                    int min=9999;
                    for(int j=0;j<3;j++){
                        if(HM.get(AL.get(j))<min){
                            min=HM.get(AL.get(j));
                            index=j;
                        }
                    }
                    AL.set(index,ele);
                    pf++;
                    
                }
                HM.put(ele,i);
                System.out.println(AL);
            }
            }
            System.out.println("PageFaults: "+pf);
       
    }
}
