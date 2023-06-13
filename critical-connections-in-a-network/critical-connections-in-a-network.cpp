class Solution {
    int timer=0; vector<vector<int>>ans;
    void dfs(vector<vector<int>>&adj,vector<int>&vis,vector<int>&low,vector<int>&in,int node,int par){
        vis[node]=1;
        in[node]=low[node]=timer++;
        for(auto it:adj[node]){
            if(it==par) continue;
            if(!vis[it]){
                dfs(adj,vis,low,in,it,node);
                low[node]=min(low[node],low[it]);
                if(low[it]>in[node]) ans.push_back({node,it});
            }
            else{
                low[node]=min(low[node],low[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>&connections) {
        vector<vector<int>>adj(n);
        for(auto it:connections){
            int u=it[0],v=it[1];
            adj[u].push_back(v); adj[v].push_back(u);
        }
        vector<int>vis(n,0),in(n,0),low(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]) dfs(adj,vis,low,in,i,-1);
        }
        return ans;
    }
};