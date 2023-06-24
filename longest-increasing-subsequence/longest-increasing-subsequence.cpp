class Solution {
public:
    int helper(int n,vector<int>&a,int idx,int prev,vector<vector<int>>&dp){
        if(idx==n) return 0;
        if(dp[idx][prev+1]!=-1) return dp[idx][prev+1];
        int pick=0,npick=0;
        if(prev==-1 || a[idx]>a[prev]) pick=helper(n,a,idx+1,idx,dp)+1;
        npick=helper(n,a,idx+1,prev,dp);
        return dp[idx][prev+1]=max(pick,npick);
    }
    int lengthOfLIS(vector<int>& a) {
        int n=a.size();
        vector<int>nums;
       for(int i=0;i<n;i++){
           if(!nums.size() || a[i]>nums.back()) nums.push_back(a[i]);
           else{
               int idx=lower_bound(nums.begin(),nums.end(),a[i])-nums.begin();
               nums[idx]=a[i];
           }
       }
       return nums.size();
    }
};