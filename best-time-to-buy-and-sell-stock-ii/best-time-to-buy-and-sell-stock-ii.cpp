class Solution {
public:
    int helper(vector<int>&prices,int buy,int idx,int n){
        if(idx==n) return 0;
        int a=0,b=0;
        if(buy){
            a=helper(prices,0,idx+1,n)-prices[idx];
            b=helper(prices,1,idx+1,n);
        }
        else{
            a=helper(prices,1,idx+1,n)+prices[idx];
            b=helper(prices,0,idx+1,n);
        }
        return max(a,b);
    }
    // return helper(prices,1,0,n);
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>prev(2,0);
        for(int idx=n-1;idx>=0;idx--){
            vector<int>curr(2,0);
            curr[0]=max(prev[1]+prices[idx],prev[0]);
            curr[1]=max(prev[0]-prices[idx],prev[1]);
            prev=curr;
        }
        return prev[1];
    }
};