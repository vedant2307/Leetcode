class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int sum=0,mini=INT_MAX,n=nums.size();
        int tot=accumulate(nums.begin(),nums.end(),0);
        if(k>=n) return tot;
        k=n-k;
        for(int i=0;i<n;i++){
            sum+=nums[i]; 
            if(i>=k-1){
                mini=min(mini,sum);
                sum-=nums[i-(k-1)];
            } 
        }
        return tot-mini;
    }
};