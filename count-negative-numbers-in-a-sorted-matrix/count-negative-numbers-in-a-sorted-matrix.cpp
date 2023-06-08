class Solution {
public:
    //Apporach 1: Brute Force = O(n*m)
    //Approach 2 : Binary Serach = O(n*log(m)) -> Apply upper bound on reverse of array
    //Approach 3: Two Pointer = O(n+m)
    int countNegatives(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size(),m=grid[0].size();
        int row=n-1,col=0;
        while(row>=0 && col<m){
            if(grid[row][col]<0){
                ans+=(m-col); row--;
            }
            else col++;
        }
        return ans;
    }
};