class Solution {
public:
    int helper(vector<int>& coins,int amount,int idx,int n){
        if(idx==n){
            if(amount==0) return 0;
            return 1e8;
        }
        int a=1e8;
        if(coins[idx]<=amount)a=helper(coins,amount-coins[idx],idx,n)+1;
        int b=helper(coins,amount,idx+1,n);
        return min(a,b);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        sort(rbegin(coins),rend(coins));
        vector<int>prev(amount+1,1e8);
        prev[0]=0;
        for(int idx=n-1;idx>=0;idx--){
            vector<int>curr(amount+1);
            for(int a=0;a<=amount;a++){
                curr[a]=prev[a];
                if(coins[idx]<=a) curr[a]=min(curr[a],curr[a-coins[idx]]+1);
            }
            prev=curr;
        }
        return prev[amount]==1e8 ? -1 : prev[amount];
    }
};