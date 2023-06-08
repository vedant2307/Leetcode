class Solution {
    vector<vector<int>>ans;
public:
    void helper(int num,int n,int k,vector<int>&temp){
        if(num==n+1){
            if(k==0) ans.push_back(temp);
            return;
        }
        if(k>0){
            temp.push_back(num);
            helper(num+1,n,k-1,temp);
            temp.pop_back();
        }
        helper(num+1,n,k,temp);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>temp;
        helper(1,n,k,temp);
        return ans;
    }
};