class Solution {
public:
    double maxProbability(int n,vector<vector<int>>&edges,vector<double>&succProb,int start,int end){
        vector<vector<pair<int,double>>>adj(n);
        vector<double>dist(n,0);
        int m=edges.size();
        for(int i=0;i<m;i++){
            int u=edges[i][0],v=edges[i][1];
            double c=succProb[i];
            adj[u].push_back({v,c}); adj[v].push_back({u,c});
        }
        priority_queue<pair<double,int>>pq;
        pq.push({1.0,start}); dist[start]=1.0;
        while(!pq.empty()){
            auto it=pq.top(); pq.pop();
            double p=it.first; int node=it.second;
            if(node==end) return p;
            for(auto it1:adj[node]){
                int neigh=it1.first; double d=it1.second;
                if(d*p>dist[neigh]){
                    dist[neigh]=d*p;
                    pq.push({dist[neigh],neigh});
                }
            }
        }
        return 0;
    }
};