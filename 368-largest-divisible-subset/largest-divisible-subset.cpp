class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<int>dp(n,1);
        vector<int>vis(n,0);
        int maxi=0,last=0;
        for(int idx=1;idx<n;idx++){
            vis[idx]=idx;
            for(int prev=0;prev<idx;prev++){
                if(arr[idx]%arr[prev]==0 && dp[idx]<dp[prev]+1){
                    dp[idx]=dp[prev]+1;
                    vis[idx]=prev;
                }
            }
            if(dp[idx]>maxi){
                maxi=dp[idx]; last=idx;
            }
        }
        vector<int>ans;
        ans.push_back(arr[last]);
        while(last!=vis[last]){
            last=vis[last];
            ans.push_back(arr[last]); 
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};