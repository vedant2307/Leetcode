class Solution {
public:
    int helper(vector<int>& cuts, int i, int j, vector<vector<int>>&dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=1e9;
        for(int k=i;k<=j;k++){
            int temp = (cuts[j+1]-cuts[i-1]) + helper(cuts,i,k-1,dp) + helper(cuts,k+1,j,dp);
            ans=min(ans,temp);
        }
        return dp[i][j]=ans;
    }
    int minCost(int n, vector<int>& cuts) {
        int m=cuts.size();
        sort(cuts.begin(),cuts.end());
        vector<int>temp;
        temp.push_back(0);
        for(auto it:cuts) temp.push_back(it);
        temp.push_back(n);
        vector<vector<int>>dp(m+1,vector<int>(m+1,-1));
        return helper(temp,1,m,dp);
    }
};