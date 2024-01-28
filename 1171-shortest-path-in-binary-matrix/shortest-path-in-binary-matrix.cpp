class Solution {
public:
    int dt[8][2] = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        dist[0][0]=1;
        queue<pair<int,int>>q;
        q.push({0,0});
        while(!q.empty()){
            auto front=q.front(); q.pop();
            int i=front.first,j=front.second;
            for(int k=0;k<8;k++){
                int x=dt[k][0]+i, y=dt[k][1]+j;
                if(x>=0 && y>=0 && x<n && y<n && grid[x][y]==0){
                    if(dist[x][y]>dist[i][j]+1){
                        dist[x][y] = dist[i][j]+1;
                        q.push({x,y});
                    }
                }
            }
        }
        if(dist[n-1][n-1]==1e9) return -1;
        return dist[n-1][n-1];
    }
};