class Solution {
public:
    #define ll long long 
    #define mod 1000000007
    ll helper(int n,int k,vector<vector<int>>&dp){
        if(k==0 || k>n) return 0;
        if(n<=2) return 1;
        if(dp[n][k]!=-1) return dp[n][k];
        ll pick=helper(n-1,k-1,dp);
        ll npick=(ll)(n-1)*helper(n-1,k,dp);
        return dp[n][k]=(pick+npick)%mod;
    }
    int rearrangeSticks(int n, int k) {
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return (int)(helper(n,k,dp));   
    }
};