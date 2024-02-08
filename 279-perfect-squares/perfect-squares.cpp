class Solution {
public:
    int helper(int n,vector<int>&dp){
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];
        int ans=1e9;
        for(int i=sqrt(n);i>=1;i--){
            int t=i*i;
            if(t<=n) ans=min(ans,helper(n-t,dp)+1);
        }
        return dp[n]=ans;
    }
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return helper(n,dp);
    }
};