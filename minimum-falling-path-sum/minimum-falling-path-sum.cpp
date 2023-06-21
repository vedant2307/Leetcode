class Solution {
public:
    int helper(int i,int j,int n,vector<vector<int>>&mat){
        if(i==n){
            return 0;
        }
        int a=1e9,b=1e9,c=1e9;
        if(j-1>=0) a=helper(i+1,j-1,n,mat);
        if(j+1<n) b=helper(i+1,j+1,n,mat);
        c=helper(i+1,j,n,mat);
        return min(a,min(b,c))+mat[i][j];
    }
    int minFallingPathSum(vector<vector<int>>&mat) {
        int n=mat.size();
        vector<int>prev=mat[0];
        for(int i=1;i<n;i++){
            vector<int>curr(n,0);
            for(int j=0;j<n;j++){
                int a=1e9,b=1e9,c=1e9;
                if(j-1>=0) a=prev[j-1];
                if(j+1<n) b=prev[j+1];
                c=prev[j];
                curr[j] =  min(a,min(b,c))+mat[i][j];                
            }
            prev=curr;
        }
        return *min_element(prev.begin(),prev.end());
    }
};