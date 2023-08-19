class DisJointSet
{
    vector<int>rank,parent,size;
    public:

    DisJointSet(int n)
    {
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
            parent[i]=i;
    }
    int findPar(int node)
    {
        if(node==parent[node])
            return node;
        return parent[node]=findPar(parent[node]);
    }
    void unionByRank(int u,int v)
    {
        int upu=findPar(u);
        int upv=findPar(v);
        if(upu==upv) return;
        if(rank[upu]<rank[upv])
        {
            parent[upu]=upv;
        }
        else if(rank[upu]>rank[upv])
        {
            parent[upv]=upu;
        }
        else
        {
            parent[upv]=upu;
            rank[upu]++;
        }
    }
    void unionBySize(int u,int v)
    {
        int upu=findPar(u);
        int upv=findPar(v);
        if(upu==upv) return;
        if(size[upu]<size[upv])
        {
            parent[upu]=upv;
            size[upv]+=size[upu];
        }
        else
        {
            parent[upv]=upu;
            size[upu]+=size[upv];
        }
    }
    
};
class Solution {
public:
    int sum,m;
    int helper(vector<vector<int>>&redges,vector<vector<int>>&edges,int pre,int block,int n){
        DisJointSet ds(n);
        int s=0;
        if(pre!=-1){
            int u=edges[redges[pre][1]][0],v=edges[redges[pre][1]][1];
            int wt=redges[pre][0];
            ds.unionBySize(u,v);
            s+=wt;
        }
        for(int i=0;i<m;i++){
            if(block==i) continue; 
            int u=edges[redges[i][1]][0],v=edges[redges[i][1]][1];
            int wt=redges[i][0];
            if(ds.findPar(u)!=ds.findPar(v)){
                ds.unionBySize(u,v);
                s+=wt;
            }
        }
        for(int i=0;i<n;i++) if(ds.findPar(i)!=ds.findPar(0)) return INT_MAX;
        return s;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<vector<int>>ans(2),redges;
        DisJointSet ds(n);
        m=edges.size();
        for(int i=0;i<m;i++){
            int wt=edges[i][2];
            redges.push_back({wt,i});
        }
        sort(redges.begin(),redges.end());
        sum=0;
        for(int i=0;i<m;i++){
            int u=edges[redges[i][1]][0],v=edges[redges[i][1]][1];
            int wt=redges[i][0];
            if(ds.findPar(u)!=ds.findPar(v)){
                ds.unionBySize(u,v);
                sum+=wt;
            }
        }
        for(int i=0;i<m;i++){
            if(sum<helper(redges,edges,-1,i,n)) ans[0].push_back(redges[i][1]);
            else if(sum==helper(redges,edges,i,-1,n)) ans[1].push_back(redges[i][1]);
        }
        return ans;
    }
};