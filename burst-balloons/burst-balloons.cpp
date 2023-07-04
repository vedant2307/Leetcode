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
    // return helper(nums,1,m-2,dp);
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int m=nums.size();
        vector<vector<int>>dp(m,vector<int>(m,0));
        for(int i=m-2;i>=1;i--){
            for(int j=i;j<m-1;j++){
                int ans=0;
                for(int k=i;k<=j;k++){
                    int temp = (nums[j+1]*nums[i-1]*nums[k]) + dp[i][k-1] + dp[k+1][j];
                    ans=max(ans,temp);
                }
                dp[i][j]=ans;
            }
        }
        return dp[1][m-2];
    }
};