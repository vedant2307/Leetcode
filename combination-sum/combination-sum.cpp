class Solution {
public:
    vector<vector<int>>ans;
    void helper(vector<int>& nums, vector<int>&temp, int t, int idx, int n){
        if(idx==n){
            if(t==0) ans.push_back(temp); 
            return;
        }
        if(nums[idx]<=t){
            temp.push_back(nums[idx]);
            helper(nums,temp,t-nums[idx],idx,n);
            temp.pop_back();
        }
        helper(nums,temp,t,idx+1,n);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<int>temp;
        helper(candidates,temp,target,0,n);
        return ans;
    }
};