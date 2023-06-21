class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        sort(rbegin(coins),rend(coins));
        vector<int>prev(amount+1);
        prev[0]=1;
        for(int idx=n-1;idx>=0;idx--){
            vector<int>curr(amount+1);
            for(int a=0;a<=amount;a++){
                curr[a]=prev[a];
                if(coins[idx]<=a) curr[a]+=curr[a-coins[idx]];
            }
            prev=curr;
        }
        return prev[amount];
    }
};