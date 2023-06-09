class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n=nums.size();
        int tot=accumulate(nums.begin(),nums.end(),0);
        if(k>=n) return tot;
        int sum=0,ans=INT_MIN;
        k=n-k;
        for(int i=0;i<n;i++){
            sum+=nums[i]; 
            if(i>=k-1){
                ans=max(tot-sum,ans);
                sum-=nums[i-(k-1)];
            } 
        }
        return ans;
    }
};