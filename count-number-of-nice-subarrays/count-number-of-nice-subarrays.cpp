class Solution {
public:
    int helper(vector<int>& nums,int k,int n){
        int i=0,j=0,cnt=0,ans=0;
        while(i<n){
            if(nums[i]%2) cnt++;
            while(cnt>k){
                if(nums[j]%2) cnt--; j++;
            }
            ans+=(i-j+1);
            i++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        return helper(nums,k,n)-helper(nums,k-1,n);
    }
};