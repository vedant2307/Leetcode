class Solution {
public:
    int helper(vector<vector<int>>& grid, int row, int col1, int col2, int n, int m,vector<vector<vector<int>>>&dp){
        if(row==n) return 0;
        if(dp[row][col1][col2]!=-1) return dp[row][col1][col2]; 
        int ans=0;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                int c1=col1+i, c2=col2+j;
                if(c1>=0 && c2>=0 && c1<m && c2<m){
                    if(col1==col2) ans=max(ans,helper(grid,row+1,c1,c2,n,m,dp)+grid[row][col1]);
                    else ans=max(ans,helper(grid,row+1,c1,c2,n,m,dp)+grid[row][col1]+grid[row][col2]);
                }
            }
        } 
        return dp[row][col1][col2]=ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1,vector<int>(m+1,-1)));
        return helper(grid,0,0,m-1,n,m,dp);
    }
};