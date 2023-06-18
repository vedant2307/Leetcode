class Solution {
    int mod = 1e9+7;
    int arr[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
public:
    void helper(int n,int m,vector<vector<int>>&grid,vector<vector<int>>&indeg){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<4;k++){
                    int x=i+arr[k][0],y=j+arr[k][1];
                    if(x>=0 && y>=0 && x<n && y<m && grid[i][j]<grid[x][y]){
                        indeg[x][y]++;
                    }
                }
            }
        }
        return;
    }
    int countPaths(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),ans=0;
        vector<vector<int>>indeg(n,vector<int>(m));
        vector<vector<int>>dp(n,vector<int>(m,1));
        helper(n,m,grid,indeg);
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(indeg[i][j]==0) q.push({i,j});
            }
        }
        while(!q.empty()){
            auto it=q.front(); q.pop();
            int i=it.first,j=it.second;
            ans = (ans+dp[i][j])%mod;
            for(int k=0;k<4;k++){
                int x=i+arr[k][0],y=j+arr[k][1];
                if(x>=0 && y>=0 && x<n && y<m && grid[i][j]<grid[x][y]){
                    indeg[x][y]--;
                    dp[x][y]=(dp[x][y]+dp[i][j])%mod;
                    if(indeg[x][y]==0){
                        q.push({x,y});
                    }
                }
            }
        }
        return ans;
    }
};