class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=n-1;
        vector<int>ans(n);
        for(int k=n-1;k>=0;k--) {
            if(abs(nums[l])>abs(nums[r])) ans[k]=nums[l]*nums[l++];
            else ans[k]=nums[r]*nums[r--];
        }
        return ans;
    }
};