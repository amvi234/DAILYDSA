public class bankers {
    int m=5,n=3;
    int [][]alloc;
    int [][]max;
    int need[][]=new int[m][n];
    int []avail;
   

    int safesequence[] = new int[n];

    void initializeval(){
        alloc =new int[][] { { 0, 1, 0 }, //P0  
        { 2, 0, 0 }, //P1
        { 3, 0, 2 }, //P2
        { 2, 1, 1 }, //P3
        { 0, 0, 2 } };
        max =new int[][]{ { 7, 5, 3 }, //P0
        { 3, 2, 2 }, //P1
        { 9, 0, 2 }, //P2
        { 2, 2, 2 }, //P3
        { 4, 3, 3 } };
        avail=new int[]{3,3,2};
    }
    void issafe(){
        int count=0;
        boolean visited[]=new boolean[n];
        for(int i=0;i<n;i++ ){
            visited[i]=false;
        }
        int work[]=new int[m];
        for(int i=0;i<n;i++){
            
                work[i]= avail[i];
            }
        
        while(count<0){
                boolean flag=false;
                for(int i=0;i<n;i++){
                    if(visited[i]==false) {
                        int j;
                        for(j=0;i<n;i++){
                            if(need[i][j]>work[j]){
                               
                                break;
                            }
                            if(j==m){
                                flag=true;
                                safesequence[count++]=i;
                                visited[i]=true;
                                for(j=0;j<m;j++){
                                    work[j]=work[j]+alloc[i][j];
                                }
                            }
                        }
                    }
                }
        if(flag==false){
                break;
        }
        else
    {
        //System.out.println("The given System is Safe");
        System.out.println("Following is the SAFE Sequence");
                for (int i = 0;i < n; i++)
        {
            System.out.print("P" + safesequence[i]);
            if (i != n-1)
            System.out.print(" -> ");
        }
    }

            }
    }
    void calculateneed(){
        
            for (int i = 0;i < n; i++)
            {
                for (int j = 0;j < m; j++)
                 {
                need[i][j] = max[i][j]-alloc[i][j];
                 }
            }       
            
         
    }
    public static void main(String[] args){
        bankers gfg = new bankers();

        gfg.initializeval();
        gfg.calculateneed();
        gfg.issafe();
    }
}