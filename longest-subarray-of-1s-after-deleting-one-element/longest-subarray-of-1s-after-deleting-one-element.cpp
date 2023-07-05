class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0,j=0,ans=0,cnt=1,n=nums.size();
        while(j<n){
            while(j<n && cnt>=0){
                if(nums[j]==0) cnt--;
                j++;
            }
            if(cnt>=0) ans=max(ans,j-i-1);
            else ans=max(ans,j-i-2);
            while(i<j && cnt==-1){
                if(nums[i]==0) cnt++;
                i++;
            }
        } 
        return ans;
    }
};