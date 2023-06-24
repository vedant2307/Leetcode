class Solution {
public:
    
    int helper(vector<int>&rods,int idx,int n,int diff,unordered_map<int,int>mp[]){
        if(idx==n){
            if(diff==0) return 0;
            return -1e9;
        }
        if(mp[idx].count(diff)) return mp[idx][diff];

        int a=helper(rods,idx+1,n,diff,mp);
        int b=rods[idx]+helper(rods,idx+1,n,diff+rods[idx],mp);
        int c=helper(rods,idx+1,n,diff-rods[idx],mp);

        return mp[idx][diff]=max(a,max(b,c));
    }
    int tallestBillboard(vector<int>& rods) {
        int n=rods.size();
        unordered_map<int,int>mp[n];
        int ans = helper(rods,0,n,0,mp); 
        return ans<0 ? 0 : ans;
    }
};