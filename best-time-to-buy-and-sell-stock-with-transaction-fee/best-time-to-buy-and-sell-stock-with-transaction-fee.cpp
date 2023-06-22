class Solution {
public:
    int helper(vector<int>& prices,int idx,int n,int buy,int fee,vector<vector<int>>&dp){
        if(idx==n) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        int a=0,b=0;
        if(buy){
            a=helper(prices,idx+1,n,0,fee,dp)-prices[idx];
            b=helper(prices,idx+1,n,1,fee,dp);
        }
        else{
            a=helper(prices,idx+1,n,1,fee,dp)+(prices[idx]-fee);
            b=helper(prices,idx+1,n,0,fee,dp); 
        }
        return dp[idx][buy]=max(a,b);
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return helper(prices,0,n,1,fee,dp);
    }
};