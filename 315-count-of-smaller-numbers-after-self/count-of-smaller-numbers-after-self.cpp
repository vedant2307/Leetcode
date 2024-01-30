class Solution {
public:
    void MergeSort(vector<int>&nums ,vector<int>&arr, vector<int>&ans, int low, int mid, int high){
        int left_size = mid-low+1, right_size=high-mid;
        vector<int>left(left_size);
        vector<int>right(right_size);

        for(int k=0;k<left_size;k++) left[k] = nums[k+low];
        for(int k=0;k<right_size;k++) right[k] = nums[k+mid+1];
        
        int i=0,j=0,k=low;

        while(i<left_size &&  j<right_size){
            if(arr[left[i]]<=arr[right[j]]) nums[k++] = right[j++];
            else {
                ans[left[i]] += (right_size-j);
                nums[k++] = left[i++];
            }
        }
        while(i<left_size) nums[k++] = left[i++];
        //while(j<right_size) nums[k++] = right[j++];
        return;
    }

    void Merge(vector<int>&nums, vector<int>&arr,vector<int>&ans, int low, int high){
        if(low<high){
            int mid = low+(high-low)/2;
            Merge(nums, arr, ans, low, mid);
            Merge(nums, arr, ans, mid+1, high);
            MergeSort(nums, arr, ans, low, mid, high);
        }
        else return;
    }

    vector<int> countSmaller(vector<int>& arr) {
        int n=arr.size();
        vector<int>nums(n);
        for(int i=0;i<n;i++) nums[i]=i;
        vector<int>ans(n);
        Merge(nums, arr, ans, 0 ,n-1);
        return ans;
    }
};