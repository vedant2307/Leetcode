class Solution {
public:
    int helper(vector<int>&arr,int low,int high,int num){
        while(low<=high){
            int mid = low+(high-low)/2;
            if(arr[mid]>=num) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n=arr.size();
        int r=n-1;
        while(r>0 && arr[r]>=arr[r-1]) r--;
        //if(r==0) return r;
        int ans = r;
        for(int l=0;l<r && (l==0 || arr[l-1]<=arr[l]); l++){
            r = helper(arr,r,n-1,arr[l]);
            ans=min(ans,r-l-1);
        }
        return ans;
    }
};