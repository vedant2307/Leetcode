class Solution {
public:
    vector<vector<int>>ans;
    int n;
    void helper(vector<int>& vec, int target, vector<int>temp, int idx){
        if(idx==n){
            if(target==0) ans.push_back(temp); 
            return;
        }
        helper(vec, target, temp, idx+1);
        if(target-vec[idx]>=0) {
            temp.push_back(vec[idx]);
            helper(vec,target-vec[idx],temp,idx);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n=candidates.size();
        vector<int>temp;
        helper(candidates, target, temp, 0);
        return ans;
    }
};