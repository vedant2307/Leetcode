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
    // return helper(prices,0,n,1,fee,dp);
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        for(int idx=n-1;idx>=0;idx--){
            for(int buy=0;buy<=1;buy++){
                int a=0,b=0;
                if(buy){
                    a=dp[idx+1][0]-prices[idx];
                    b=dp[idx+1][1];
                }
                else{
                    a=dp[idx+1][1]+(prices[idx]-fee);
                    b=dp[idx+1][0]; 
                }
                dp[idx][buy]=max(a,b);
            }
        }
        return dp[0][1];
    }
};