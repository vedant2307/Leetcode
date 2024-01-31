class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,set<int>>mp; queue<pair<int,int>>q; vector<bool>vis(n);
        for(int i=0;i<n;i++) mp[arr[i]].insert(i);
        vis[0]=1;
        q.push({0,0});
        while(!q.empty()){
            auto it = q.front(); 
            int idx=it.first,steps=it.second; q.pop();
            if(idx==n-1) return steps;
            if(idx-1>=0 && !vis[idx-1]) {
                q.push({idx-1,steps+1});
                vis[idx-1]=1;
            }
            if(idx+1<n && !vis[idx+1]) {
                q.push({idx+1,steps+1});
                vis[idx+1]=1;
            }
            for(auto itr:mp[arr[idx]]){
                if(!vis[itr]) {
                    q.push({itr,steps+1});
                    vis[itr]=1;
                    mp[arr[idx]].erase(itr);
                }
            }
        }
        return 0;
    }
};