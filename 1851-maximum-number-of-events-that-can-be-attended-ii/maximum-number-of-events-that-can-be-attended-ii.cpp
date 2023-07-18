class Solution {
public:
    int helper(vector<vector<int>>& events, int k, int idx, int n, vector<vector<int>>&dp){
        if(idx>=n || k==0) return 0;
        if(dp[idx][k]!=-1) return dp[idx][k];
        int next= upper_bound(begin(events)+idx,end(events),events[idx][1],
        [](int t,vector<int>&v){return v[0]>t;})-begin(events);
        int a = helper(events,k-1,next,n,dp)+events[idx][2];
        int b = helper(events,k,idx+1,n,dp);
        return dp[idx][k]=max(a,b);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        int n=events.size();
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        sort(events.begin(),events.end());
        return helper(events,k,0,n,dp);
    }
};