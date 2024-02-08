class Solution {
public:
    int helper(vector<int>&nums, int k){
        unordered_map<int,int>mp;
        int j=0,ans=0;
        for(int i=0;i<size(nums);i++){
            if(mp[nums[i]]++==0) k--;
            while(k<0){
                if(--mp[nums[j++]]==0) k++;
            }
            ans+=(j-i+1);
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums,k-1)-helper(nums,k);
    }
};