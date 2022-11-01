int minSwap(int arr[], int n, int k) {
        // Complet the function
        int count=0;
        for(int i=0;i<n;i++){
            if(arr[i]<=k){
                count++;
            }
        }
        int bad=0;
        for(int i=0;i<count;i++){
            if(arr[i]>k){
                bad++;
            }
        }
        int ans = bad;
        for(int i=0,j=count;j<n;j++,i++){
            if(arr[j]>k){
                bad++;
            }
            if(arr[i]>k){
                bad--;
            }
            ans = min(ans,bad);
        }
        return ans;
    }