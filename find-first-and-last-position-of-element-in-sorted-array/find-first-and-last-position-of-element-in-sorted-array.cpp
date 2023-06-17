class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int idx1=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int idx2=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(idx1==n || nums[idx1]!=target) return {-1,-1};
        return {idx1,idx2-1};
    }
};