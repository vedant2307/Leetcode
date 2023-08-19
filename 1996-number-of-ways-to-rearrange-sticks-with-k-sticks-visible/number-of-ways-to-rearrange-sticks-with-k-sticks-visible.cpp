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
    // return (int)(helper(n,k,dp));   
    int rearrangeSticks(int n, int k) {
        vector<vector<ll>>dp(n+1,vector<ll>(k+1));
        for(int i=1;i<=2;i++){
            for(int j=1;j<=i && j<=k;j++){
                dp[i][j]=1;
            }
        }
        for(int i=3;i<=n;i++){
            for(int j=1;j<=i && j<=k;j++){
                ll pick=dp[i-1][j-1];
                ll npick=(ll)(i-1)*dp[i-1][j];
                dp[i][j]=(pick+npick)%mod;
            }
        }
        return (int)dp[n][k];
    }
};