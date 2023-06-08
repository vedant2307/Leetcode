class Solution {
    vector<vector<int>>ans;
public:
    void helper(vector<int>&nums,int idx,int n){
        if(idx==n){
            ans.push_back(nums); return;
        }
        for(int k=idx;k<n;k++){
            swap(nums[idx],nums[k]);
            helper(nums,idx+1,n);
            swap(nums[idx],nums[k]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        helper(nums,0,n);
        return ans;
    }
};