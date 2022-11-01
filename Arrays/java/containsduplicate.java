static int containsduplicate(int nums[]){
    arrays.sort(nums);
    for(int i=1;i<nums.length;i++){
        if(nums[i]==nums[i-1]){
            return true;
        }
    }
    return false;
}