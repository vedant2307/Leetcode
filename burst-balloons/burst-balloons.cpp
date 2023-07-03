class Solution {
public:
    int helper(vector<int>& cuts, int i, int j, vector<vector<int>>&dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        for(int k=i;k<=j;k++){
            int temp = (cuts[j+1]*cuts[i-1]*cuts[k]) + helper(cuts,i,k-1,dp) + helper(cuts,k+1,j,dp);
            ans=max(ans,temp);
        }
        return dp[i][j]=ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int m=nums.size();
        vector<vector<int>>dp(m,vector<int>(m,-1));
        return helper(nums,1,m-2,dp);
    }
};