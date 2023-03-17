class Solution {
    public String convert(String s, int numRows) {
        if(numRows==1) return s;
        int p=s.length()/numRows;
        int t=p+(numRows-2)*(p-1);

        int l=0;
        int i=0;
        char[][] m = new char[numRows][s.length()];
        for(int x=0; x<numRows; x++){
            Arrays.fill(m[x],'0'); //fill arr[] with '0'
        }
        int j=0;
        while(l!=s.length()){
            
            while(i<numRows && l!=s.length()){
                    m[i][j]=s.charAt(l);
                    l++;
                    i++;
            }
            i--;
            while(i>0 && l!=s.length()){
                i--;
                j++;
                m[i][j]=s.charAt(l);
                l++;  
            }
            i++;
        }
        StringBuilder q = new StringBuilder();
        for(int g=0;g<numRows;g++){
            for(int d=0;d<m[g].length;d++){
                if(m[g][d]!='0'){
                    q.append(m[g][d]);
                }
            }
        }
        return q.toString();
    }
}