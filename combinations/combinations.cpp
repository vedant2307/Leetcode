class Solution {
    vector<vector<int>>ans;
public:
    void helper(int num,int n,int k,vector<int>&temp){
        if(k==0){
            ans.push_back(temp); return;
        }
        for(int idx=num;idx<=n;idx++){
            temp.push_back(idx);
            helper(idx+1,n,k-1,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>temp;
        helper(1,n,k,temp);
        return ans;
    }
};