class Solution {
public:
    int helper(vector<int>&arr, int k, int n, int idx, vector<int>&dp){
        if(idx==n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int ans=0,maxi=-1,temp=0;
        for(int i=idx;i<min(idx+k,n);i++){
            maxi=max(maxi,arr[i]); temp++;
            int sum = temp*maxi + helper(arr,k,n,i+1,dp);
            ans=max(ans,sum);
        }
        return dp[idx]=ans;
    }
    // return helper(arr,k,n,0,dp);
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n+1,0);
        for(int idx=n-1;idx>=0;idx--){
            int ans=0,maxi=-1,temp=0;
            for(int i=idx;i<min(idx+k,n);i++){
                maxi=max(maxi,arr[i]); temp++;
                int sum = temp*maxi + dp[i+1];
                ans=max(ans,sum);
            }
            dp[idx]=ans; 
        }
        return dp[0];
    }
};