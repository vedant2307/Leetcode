class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(),idx1=n-2,idx2=n-1;
        while(idx1>=0 && nums[idx1]>=nums[idx1+1]) idx1--;
        if(idx1>=0){
            while(idx2>=idx1 && nums[idx2]<=nums[idx1]) idx2--;
            swap(nums[idx2],nums[idx1]);
        }
        reverse(nums.begin()+idx1+1,nums.end());
        return;
    }
};