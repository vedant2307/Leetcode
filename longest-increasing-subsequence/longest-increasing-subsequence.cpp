class Solution {
public:
    int helper(int n,vector<int>&a,int idx,int prev,vector<vector<int>>&dp){
        if(idx==n) return 0;
        if(dp[idx][prev+1]!=-1) return dp[idx][prev+1];
        int pick=0,npick=0;
        if(prev==-1 || a[idx]>a[prev]) pick=helper(n,a,idx+1,idx,dp)+1;
        npick=helper(n,a,idx+1,prev,dp);
        return dp[idx][prev+1]=max(pick,npick);
    }
    int lengthOfLIS(vector<int>& a) {
        int n=a.size();
      vector<int>pre(n+1,0);
       for(int idx=n-1;idx>=0;idx--){
           vector<int>curr(n+1,0);
           for(int prev=idx-1;prev>=-1;prev--){
               int len=pre[prev+1];
               if(prev==-1 || a[idx]>a[prev]) len=max(len,pre[idx+1]+1);
               curr[prev+1]=len;
           }
           pre=curr;
       }
       return pre[0];
    }
};