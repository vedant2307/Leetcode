class Solution {
public:
    void transpose(vector<vector<int>>& grid,int n){
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(grid[i][j],grid[j][i]);
            }
        }
        return ;
    }
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size(),ans=0;
        map<vector<int>,int>mp;
        for(int i=0;i<n;i++){
            mp[grid[i]]++;
        }
        transpose(grid,n);
        for(int i=0;i<n;i++){
            if(mp.count(grid[i])) ans+=mp[grid[i]];
        }
        return ans;
    }
};