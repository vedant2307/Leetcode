class Solution {
public:
    string longestPalindrome(string str) {
        int n=str.length(),len=1;
        string ans=str.substr(0,1);
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++) dp[i][i]=true;
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(j-i==1){
                    if(str[i]==str[j]){
                        if(len<2) { len=2; ans=str.substr(i,2); }
                        dp[i][j]=true;
                    }
                }
                else{
                    if(str[i]==str[j] && dp[i+1][j-1]){
                        dp[i][j]=true;
                        if(len<j-i+1){
                            len=j-i+1;
                            ans=str.substr(i,len);
                        }
                    }
                }
            }
        }
        return ans;
    }
};