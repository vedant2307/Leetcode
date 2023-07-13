class Solution {
public:
    bool canFinish(int v, vector<vector<int>>& edges) 
    {
        int e=edges.size();
            vector<vector<int>>list(v+1);
    vector<int>indeg(v+1,0);
    for(int i=0;i<e;i++)
    {
        int u=edges[i][1];
        int V=edges[i][0];
        list[u].push_back(V);
        indeg[V]++;
    }
    queue<int>q;
    vector<int>res;
    for(int i=0;i<v;i++)
    {
        if(indeg[i]==0)
            q.push(i);
    }
    while(!q.empty())
    {
        int front=q.front();
        res.push_back(front);
        q.pop();
        for(auto i:list[front])
        {
            indeg[i]--;
            if(indeg[i]==0)
                q.push(i);
        }
    }
    if(res.size()==v)
        return true;
    return false;    
    }
};