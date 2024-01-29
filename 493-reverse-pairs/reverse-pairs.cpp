#define int1 long long
class Solution {
public:

    long long ans ;

    void MergeSort(vector<int>&arr, int1 low, int1 mid, int1 high){
        int1 left_size = mid-low+1, right_size=high-mid;
        vector<int1>left(left_size);
        vector<int1>right(right_size);

        for(int k=0;k<left_size;k++) left[k] = arr[k+low];
        for(int k=0;k<right_size;k++) right[k] = arr[k+mid+1];
        
        int1 i=0,j=0,k=low;

        while(i<left_size && j<right_size){
            if(left[i]<=2*right[j]) i++;
            else{
                int1 num=2*right[j];
                int1 idx=upper_bound(left.begin(),left.end(),num)-left.begin();
                ans += (left_size-idx);
                j++;
            }
        }

        i=0; j=0;

        while(i<left_size &&  j<right_size){
            if(left[i]<right[j]) {
                arr[k++] = left[i++];
            }
            else {
                arr[k++] = right[j++];
            }
        }
        while(i<left_size) arr[k++] = left[i++];
        while(j<right_size) arr[k++] = right[j++];
        return;
    }

    void Merge(vector<int>&arr, int low, int high){
        if(low<high){
            int mid = low+(high-low)/2;
            Merge(arr, low, mid);
            Merge(arr, mid+1, high);
            MergeSort(arr, low, mid, high);
        }
        else return;
    }
    int reversePairs(vector<int>& arr) {
        int n=arr.size();
        ans=0LL;
        Merge(arr, 0 ,n-1);
        return (int)ans;
    }
};