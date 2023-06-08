class Solution {
public:
    int helper(int low,int high,vector<int>&temp){
        while(low<=high){
            int mid=low+(high-low)/2;
            if(temp[mid]<0) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
    int countNegatives(vector<vector<int>>& grid) {
        int ans=0,n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            int idx=helper(0,m-1,grid[i]);
            ans+=(m-idx);
        }
        return ans;
    }
};