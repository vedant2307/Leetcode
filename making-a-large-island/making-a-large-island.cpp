class DisJointSet{
    public:
    vector<int>par,size;
    DisJointSet(int n){
        size.resize(n,1); par.resize(n);
        for(int i=0;i<n;i++) par[i]=i;
    }
    int findParent(int node){
        if(node==par[node]) return node;
        return par[node]=findParent(par[node]);
    }
    void unionBySize(int u,int v){
        int pu=findParent(u),pv=findParent(v);
        if(pu==pv) return;
        if(size[pu]>=size[pv]){
            size[pu]+=size[pv];
            par[pv]=pu;
        }
        else{
            size[pv]+=size[pu];
            par[pu]=pv;
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int N=n*n;
        DisJointSet ds(N);
        int arr[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int u=i*n+j;
                    for(int idx=0;idx<4;idx++){
                        int x=i+arr[idx][0],y=j+arr[idx][1];
                        if(x>=0 && y>=0 && x<n && y<n && grid[x][y]==1){
                            int v=x*n+y;
                            ds.unionBySize(u,v);
                        }
                    }
                }
            }
        }
        int ans=*max_element(ds.size.begin(),ds.size.end());
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    int cnt=1; set<int>st;
                    for(int idx=0;idx<4;idx++){
                        int x=i+arr[idx][0],y=j+arr[idx][1];
                        if(x>=0 && y>=0 && x<n && y<n && grid[x][y]==1){
                            int v=x*n+y;
                            int p=ds.findParent(v);
                            if(st.find(p)==st.end()){
                                cnt+=ds.size[p];
                                st.insert(p);
                            }
                        }
                    }
                    ans=max(ans,cnt);
                }
            }
        }
        return ans;
    }
}; 