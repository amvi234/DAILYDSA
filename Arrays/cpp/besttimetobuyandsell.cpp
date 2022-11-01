class Solution {
    public int maxProfit(int[] prices) {
        int profit=0;
        int max;
        int i=0;
        int j=1;
        
        while(j<prices.length){
            if(prices[i]<prices[j]){
               int temp=prices[j]-prices[i];
                if(temp>profit){
                    profit=temp;
                }
            } 
            else{
                i=j;
            }
            j++;
        }
        return profit;
    }
}