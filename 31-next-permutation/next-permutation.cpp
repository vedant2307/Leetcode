class Solution {
public:
    void Reverse(int i,int j,vector<int>&nums){
        while(i<j) swap(nums[i++],nums[j--]);
        return ;
    }
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int i=n-1,j=n-1;
        while(i>0 && nums[i]<=nums[i-1]) i--;
        if(i==0) reverse(nums.begin(),nums.end());
        else{
            while(j>=i && nums[j]<=nums[i-1]) j--;
            swap(nums[i-1],nums[j]);
            reverse(nums.begin()+i,nums.end());
        }
        return ;
    }
};