package java;
class Solution {
    public int[] productExceptSelf(int[] nums) {
        int answer []= new int[nums.length];
        if(nums.length==0){
            return answer;
        }
        int temp=1;
        for(int j=0;j<nums.length;j++){
            answer[j] = 1;
        }
        int i;
        for( i=0;i<nums.length;i++){
            answer[i]=temp;
            temp *= nums[i];
        }
        for(int k=0;k<nums.length;k++){
            System.out.println(answer[k]);
        }
         temp=1;
        for( i=nums.length-1;i>=0;i--){
                answer[i]*=temp;
                temp*=nums[i];
        }
        return answer;
    }
}