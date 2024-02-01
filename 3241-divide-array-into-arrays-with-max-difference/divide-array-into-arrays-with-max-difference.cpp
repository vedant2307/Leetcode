class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>>ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;){
            if(nums[i+2]-nums[i]<=k) ans.push_back({nums[i],nums[i+1],nums[i+2]});
            else return {};
            i=i+3;
        }
        return ans;
    }
};