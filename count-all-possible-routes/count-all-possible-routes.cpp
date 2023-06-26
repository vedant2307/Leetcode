class Solution {
public:
    int mod=1e9+7;
    int helper(vector<int>&nums,int start,int finish,int fuel,int n,vector<vector<int>>&dp){
        if(fuel<0) return 0;
        if(dp[start][fuel]!=-1) return dp[start][fuel];
        int ans=0;
        if(start==finish) ans++;
        for(int k=0;k<n;k++){
            if(k==start) continue;
            int temp=abs(nums[start]-nums[k]);
            ans = (ans+helper(nums,k,finish,fuel-temp,n,dp))%mod;
        }
        return dp[start][fuel]=ans;
    }
    // return helper(locations,start,finish,fuel,n,dp);
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n=locations.size();
        vector<vector<int>>dp(n,vector<int>(fuel+1,0));
        for(int i=0;i<=fuel;i++) dp[finish][i]=1;
        for(int f=0;f<=fuel;f++)
        {
            for(int idx=0;idx<n;idx++)
            {
                for(int k=0;k<n;k++){
                    int temp=abs(locations[idx]-locations[k]);
                    if(k==idx || temp>f) continue;
                    dp[idx][f] = (dp[idx][f]+dp[k][f-temp])%mod;
                }
            }
        }
        return dp[start][fuel];
    }
};