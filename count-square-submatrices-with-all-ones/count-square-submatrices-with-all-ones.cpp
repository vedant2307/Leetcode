class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int N=matrix.size(), M=matrix[0].size();
        int sum=0;
        vector<vector<int>>dp(N,vector<int>(M,0));
        for(int i=0;i<N;i++) { dp[i][0]=matrix[i][0];  }
        for(int i=0;i<M;i++) { dp[0][i]=matrix[0][i];  }
        
        for(int i=1;i<N;i++){
            for(int j=1;j<M;j++){
                if(matrix[i][j]==1){
                    dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
            
                }
            }
        }
        
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                sum+= dp[i][j];
            }
        }
        return sum;
    }
};