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
        sort(cuts.begin(),cuts.end());
        int m=cuts.size();
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        vector<vector<int>>dp(m+2,vector<int>(m+2,0));
        
        for(int i=m;i>=1;i--){
            for(int j=i;j<=m;j++){
               int ans=1e9;
                for(int k=i;k<=j;k++){
                    int temp = (cuts[j+1]-cuts[i-1]) + dp[i][k-1] + dp[k+1][j];
                    ans=min(ans,temp);
                }
                dp[i][j]=ans;  
            }
        }
        return dp[1][m];
    }
};