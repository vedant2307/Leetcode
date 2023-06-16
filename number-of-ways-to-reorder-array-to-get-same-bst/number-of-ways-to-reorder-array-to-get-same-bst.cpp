class Solution {
    #define ll long long
    #define mod 1000000007
public:
    ll helper(vector<int>&nums,vector<vector<ll>>&dp){
        if(nums.size()<=2) return 1;
        vector<int>left,right;
        int root=nums[0];
        for(int i=1;i<nums.size();i++){
            if(root>nums[i]) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }
        return (((helper(left,dp)*helper(right,dp))%mod)*dp[nums.size()-1][left.size()])%mod;
    }
    int numOfWays(vector<int>& nums) {
        int n=nums.size();
        vector<vector<ll>>dp(n);
        for(int i=0;i<n;i++){
            dp[i].resize(i+1);
            dp[i][0]=dp[i][i]=1;
            for(int j=1;j<i;j++){
                dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%mod;
            }
        }
        return helper(nums,dp)-1;
    }
};