class Solution {
public:
    int helper(int low,int high,vector<int>&arr1,vector<int>&arr2,int k){
        while(low<=high){
            int mid=low+(high-low)/2;
            int cnt=0;
            cnt+= upper_bound(arr1.begin(),arr1.end(),mid)-arr1.begin();
            cnt+= upper_bound(arr2.begin(),arr2.end(),mid)-arr2.begin();
            if(cnt<=k){
                low=mid+1;
            }
            else high=mid-1;
        }
        return low;
    }
    double func(vector<int>&arr,int size){
        if(size%2){
            return (double)arr[size/2];
        }
        else{
            return (double)(arr[size/2]+arr[size/2-1])/2;
        }
    }
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2)
    {
        // Your code goes here
         int n=arr1.size(),m=arr2.size();
         if(n==0){
             return func(arr2,m);
         }
         if(m==0){
             return func(arr1,n);
         }
        int size=n+m;
        int low=min(arr1[0],arr2[0]);
        int high=max(arr1[n-1],arr2[m-1]);
        
        if(size%2) return (double)helper(low,high,arr1,arr2,size/2);
        return ((double)helper(low,high,arr1,arr2,size/2) + (double)helper(low,high,arr1,arr2,(size/2)-1))/2;
    }
        
    
};
