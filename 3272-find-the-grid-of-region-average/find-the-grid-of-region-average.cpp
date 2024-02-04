class Solution {
public:
    vector<vector<int>> resultGrid(vector<vector<int>>& img, int thr) {
        int n=img.size(), m=img[0].size();
        vector<vector<vector<int>>>grid(n,vector<vector<int>>(m));
        vector<vector<int>>ans(n,vector<int>(m));
        for(int i=0;i<n-2;i++){
            for(int j=0;j<m-2;j++){
                bool flg=true;
                int sum=0;
                for(int x=i;x<i+3;x++){
                    for(int y=j;y<j+3;y++){
                        sum+= img[x][y];
                        flg &= x==i || abs(img[x][y]-img[x-1][y])<=thr;
                        flg &= y==j || abs(img[x][y]-img[x][y-1])<=thr;
                    }
                }
                if(flg){
                    for(int x=i;x<i+3;x++){
                        for(int y=j;y<j+3;y++){
                            grid[x][y].push_back(sum/9);
                        }
                    }
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(grid[i][j].size()){
                    int t=accumulate(grid[i][j].begin(),grid[i][j].end(),0);
                     ans[i][j] = t/grid[i][j].size();
                }
                else ans[i][j]=img[i][j];
            }
        }

        return ans;
    }
};