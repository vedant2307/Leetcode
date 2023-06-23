class Solution {
public:
    int helper(vector<int>&prices,int idx,int n,int tran){
        if(idx==n || tran==4) return 0;
        int a=0,b=0;
        if(tran%2==0){
            a=helper(prices,idx+1,n,tran+1)-prices[idx];
            b=helper(prices,idx+1,n,tran);
        }
        else{
            a=helper(prices,idx+1,n,tran+1)+prices[idx];
            b=helper(prices,idx+1,n,tran);
        }
        return max(a,b);
    }
    // return helper(prices,0,n,0);
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>prev(5);
        for(int idx=n-1;idx>=0;idx--){
            vector<int>curr(5);
            for(int tran=3;tran>=0;tran--){
                if(tran%2) curr[tran]=max(prev[tran+1]+prices[idx],prev[tran]);
                else curr[tran]=max(prev[tran+1]-prices[idx],prev[tran]);
            }
            prev=curr;
        }
        return prev[0];
    }
};