class Solution {
public:
    int mod=1000000007;
    int helper(int idx,int n,int m,int k,int maxi,vector<vector<vector<int>>>&dp){
        if(k<0) return 0;
        if(idx==n){
            if(k==0) return 1;
            return 0;
        }
        if(dp[idx][k][maxi+1]!=-1) return dp[idx][k][maxi+1];
        int ans=0;
        for(int i=1;i<=m;i++){
            if(i>maxi) ans=(ans+helper(idx+1,n,m,k-1,i,dp))%mod;
            else ans=(ans+helper(idx+1,n,m,k,maxi,dp))%mod; 
        }
        return dp[idx][k][maxi+1]=ans%mod;
    }
    int numOfArrays(int n, int m, int k) {
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(k+1,vector<int>(102,-1)));
        return helper(0,n,m,k,-1,dp);
    }
};