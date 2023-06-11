class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dT) {
        vector<vector<int>>mat(n,vector<int>(n,1e5));
        for(auto it:edges){
            int u=it[0],v=it[1],cost=it[2];
            mat[u][v]=cost;
            mat[v][u]=cost;
        }
        for(int i=0;i<n;i++) mat[i][i]=0;
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    mat[i][j] = min(mat[i][j],mat[i][k]+mat[k][j]);
                }
            }
        }
        int ans=-1,maxi=n+1;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(mat[i][j]<=dT) cnt++;
            }
            if(cnt<=maxi) { maxi=cnt; ans=i; }
        }
        return ans;
    }
};