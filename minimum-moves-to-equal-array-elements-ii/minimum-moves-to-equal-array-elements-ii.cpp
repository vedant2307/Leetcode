class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size(),ans1=0,ans2=0;
        if(n==1) return 0;
        sort(nums.begin(),nums.end());
        int mid=nums[(n-1)/2],mid1=nums[(n-1)/2+1];
        int avg=accumulate(nums.begin(),nums.end(),0)/n;
        for(int idx=0;idx<n;idx++){
            ans1+=abs(mid-nums[idx]);
            ans2+=abs((mid1)-nums[idx]);
        }
        return min(ans1,ans2);
    }
};