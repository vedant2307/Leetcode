class Solution {
public:
    bool canReach(string s, int minJ, int maxJ) {
        int n=size(s);
        vector<int>dp(n),prefix(n);
        dp[0]=1; prefix[0]=1;
        for(int i=1;i<n;i++){
            int l=i-maxJ,r=i-minJ;
            if(r<0) prefix[i]=prefix[i-1];
            else if(l<=0){
                if(prefix[r] && s[i]=='0'){
                    dp[i]=1;
                    prefix[i]=prefix[i-1]+1;
                }
                else prefix[i]=prefix[i-1];
            }
            else{
                int t=prefix[r]-prefix[l-1];
                if(t && s[i]=='0'){
                    dp[i]=1;
                    prefix[i]=prefix[i-1]+1;
                }
                else prefix[i]=prefix[i-1];
            }
        }
        return dp[n-1];
    }
};