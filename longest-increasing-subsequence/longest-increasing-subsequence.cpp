class Solution {
public:
    int helper(int n,vector<int>&a,int idx,int prev,vector<vector<int>>&dp){
        if(idx==n) return 0;
        if(dp[idx][prev+1]!=-1) return dp[idx][prev+1];
        int pick=0,npick=0;
        if(prev==-1 || a[idx]>a[prev]) pick=helper(n,a,idx+1,idx,dp)+1;
        npick=helper(n,a,idx+1,prev,dp);
        return dp[idx][prev+1]=max(pick,npick);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
       return helper(n,nums,0,-1,dp);
    }
};