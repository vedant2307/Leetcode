class Solution {
public:
    int helper(int i,int j,int n,vector<vector<int>>&nums){
        if(i==n-1){
            return nums[i][j];
        }
        return min(helper(i+1,j,n,nums),helper(i+1,j+1,n,nums))+nums[i][j];
    }
    // return helper(0,0,n,triangle);
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int>prev(1,triangle[0][0]);
        for(int i=1;i<n;i++){
            vector<int>curr(i+1);
            for(int j=0;j<i+1;j++){
                if(j==0) curr[j]=prev[j];
                else if(j==i) curr[j]=prev[j-1];
                else curr[j]=min(prev[j],prev[j-1]);
                curr[j]+=triangle[i][j];
            }
            prev=curr;
        }
        return *min_element(prev.begin(),prev.end());
    }
};