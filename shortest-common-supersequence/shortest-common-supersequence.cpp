class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        string ans; int n=str1.length(),m=str2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int idx1=1;idx1<=n;idx1++){
            for(int idx2=1;idx2<=m;idx2++){
                if(str1[idx1-1]==str2[idx2-1]){
                    dp[idx1][idx2]=1+dp[idx1-1][idx2-1];
                }
                else {
                    dp[idx1][idx2]=max(dp[idx1-1][idx2],dp[idx1][idx2-1]);
                }
            }
        }
        int i=n,j=m;
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                ans=str1[i-1]+ans; i--; j--;
            }
            else{
                if(dp[i-1][j]>dp[i][j-1]){
                    ans=str1[i-1]+ans; i--;
                }
                else { ans=str2[j-1]+ans; j--;} 
            }
        }
        while(i>0) {
            ans=str1[i-1]+ans; i--;
        }
        while(j>0) {
            ans=str2[j-1]+ans; j--;
        }
        return ans;
    }
};