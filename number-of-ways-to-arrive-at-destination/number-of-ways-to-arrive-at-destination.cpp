class Solution {
    #define mod 1000000007
    #define ll long long
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);
        vector<ll>dist(n,LONG_MAX),ways(n,0);
        for(auto it:roads){
            int u=it[0],v=it[1],cost=it[2];
            adj[u].push_back({v,cost});
            adj[v].push_back({u,cost});
        }
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>q;
        q.push({0,0}); dist[0]=0; ways[0]=1;
        while(!q.empty()){
            auto it=q.top(); q.pop();
            ll front=it.second,d=it.first;
            for(auto it:adj[front]){
                int neigh=it.first,t=it.second;
                if(dist[neigh]>d+(ll)t){
                   dist[neigh]=d+t; 
                   ways[neigh]=ways[front];
                   q.push({d+t,neigh});
                }
                else if(dist[neigh]==d+t){
                   ways[neigh]=(ways[neigh]+ways[front])%mod;
                }
            }
        }
        return ways[n-1];
    }
};