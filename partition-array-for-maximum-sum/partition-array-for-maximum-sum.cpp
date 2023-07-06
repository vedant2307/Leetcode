class Solution {
public:
    int helper(vector<int>&arr, int k, int n, int idx, int maxi, vector<int>&dp){
        if(idx==n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int ans=0;
        for(int i=idx;i<min(idx+k,n);i++){
            maxi=max(maxi,arr[i]);
            int temp = (i-idx)+1;
            int sum = temp*maxi + helper(arr,k,n,i+1,arr[i+1],dp);
            ans=max(ans,sum);
        }
        return dp[idx]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        arr.push_back(-1);
        vector<int>dp(n+1,-1);
        return helper(arr,k,n,0,-1,dp);
    }
};