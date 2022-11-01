#include<iostream>
using namespace std;
void inssort(int *arr,int idx,int n ){
    if(idx == n){
            return;
    }
        int curr = arr[idx];
        int j = idx - 1;

        for(j=idx-1;j >= 0;j--){
            if(curr < arr[j]){ // found greater value than curr shift to right
                arr[j + 1] = arr[j];
            }
            else // Smaller element found
                break;
        }
        arr[j + 1] = curr; //place curr element at correct place

        // one part Done recursion will do other work;
        inssort(arr , idx + 1 , n);
}
int main(){
    int arr[5]={1,9,6,3,8};
    inssort(arr,1,5);
    cout<<"After sorting: "<<endl;
    for(int i=0;i<5;i++)
        cout<<arr[i]<<" " ;
    return 0;
}