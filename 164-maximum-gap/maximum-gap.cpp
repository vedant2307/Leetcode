class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n=nums.size();
        if(n<2) return 0;
        int maxi=*max_element(nums.begin(),nums.end());
        int mini=*min_element(nums.begin(),nums.end());
        vector<int>bmax(n-1,INT_MIN),bmin(n-1,INT_MAX);
        int interval = (maxi-mini+(n-2))/(n-1);

        for(int i=0;i<n;i++){
            if(nums[i]==maxi || nums[i]==mini) continue;
            int idx = (nums[i]-mini)/(interval);
            bmax[idx]=max(nums[i],bmax[idx]);
            bmin[idx]=min(nums[i],bmin[idx]);
        }

        int prev=mini,ans=0;
        for(int idx=0;idx<n-1;idx++){
            if(bmin[idx]==INT_MAX) continue;
            ans = max(ans,bmin[idx]-prev);
            prev = bmax[idx];
        }
        ans = max(ans,maxi-prev);

        return ans;
    }
};