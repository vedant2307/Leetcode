class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& nums, vector<int>& New) {
        vector<vector<int>>ans;
        int n=nums.size(),i=0;
        while(i<n && New[0]>nums[i][1]){
            ans.push_back(nums[i++]);
        }
        while(i<n && New[1]>=nums[i][0]){
            New[0]=min(New[0],nums[i][0]);
            New[1]=max(New[1],nums[i][1]);
            i++;
        }
        ans.push_back(New);
        while(i<n){
            ans.push_back(nums[i++]);
        }
        return ans;
    }
};