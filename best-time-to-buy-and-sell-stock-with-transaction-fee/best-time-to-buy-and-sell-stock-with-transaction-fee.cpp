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
        vector<int>prev(2,0);
        for(int idx=n-1;idx>=0;idx--){
            vector<int>curr(2,0);
            curr[0] = max(prev[1]+(prices[idx]-fee),prev[0]);
            curr[1] = max(prev[0]-prices[idx],prev[1]);
            prev=curr;
        }
        return prev[1];
    }
};