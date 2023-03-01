class Solution {
public:
    // void sw(int &a,int &b){
    //     int temp=b;
    //     b=a;
    //     a=temp;
    // }
    // int partition(vector<int>& nums,int high,int low){
    //     int pivot=nums[high];
    //     int i=low-1;
    //     for(int j=low;j<=high-1;j++){
    //         if(nums[j]<pivot){
    //             i++;
    //             sw(nums[i],nums[j]);
    //         }
    //     }
    //     sw(nums[i+1],nums[high]);
    //     return i+1;
    // }
    void quickSort(vector<int>& nums,int low,int high){
        if (low >= high) return;
        
        int i = low, j = high, pivot = nums[i + (j - i) / 2];
        
        while (i <= j) {
            while (i <= j && nums[i] < pivot) ++i;
            while (i <= j && nums[j] > pivot) --j;
            
            if (i <= j) {
                int tmp = nums[i];
                nums[i++] = nums[j];
                nums[j--] = tmp;
            }
        }
        
        quickSort(nums, i, high);
        quickSort(nums, low, j);
    }
    vector<int> sortArray(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        quickSort(nums,0,high);
        return nums;
    }
};