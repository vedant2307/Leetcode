class Solution {
public:
    int helper(vector<int>&nums,int k,int n){
        if(k==0) return 0;
        int i=0,j=0,ans=0,cnt=k;
        unordered_map<int,int>mp;
        while(j<n){
            if(mp[nums[j]]++==0) cnt--;
            while(cnt<0){
                if(--mp[nums[i++]]==0) cnt++;
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        return helper(nums,k,n)-helper(nums,k-1,n);
    }
};