class Solution {
public:
    int helper(vector<int>&arr, int k, int idx, int n,vector<int>&dp){
        if(idx==n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int ans=0,maxi=-1;
        for(int i=idx;i<min(idx+k,n);i++){
            maxi=max(maxi,arr[i]);
            ans = max(ans,helper(arr,k,i+1,n,dp)+maxi*(i-idx+1));
        }
        return dp[idx]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n,-1);
        return helper(arr,k,0,n,dp);
    }
};