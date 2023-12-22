class Solution {
public:

    int helper(vector<string>&words, int idx, int n, char f,char l, vector<vector<vector<int>>>&dp){
        if(idx==n) return 0;
        if(dp[idx][f-'a'][l-'a']!=-1) return dp[idx][f-'a'][l-'a'];
        
        int a=INT_MAX,b=INT_MAX,size=words[idx].size();

        if(words[idx].back()==f) a = size-1+helper(words, idx+1, n, words[idx][0], l, dp);
        else a = size+helper(words, idx+1, n, words[idx][0], l, dp);

        if(words[idx][0]==l) b = size-1+helper(words, idx+1, n, f, words[idx].back(), dp);
        else b = size+helper(words, idx+1, n, f, words[idx].back(), dp);

        return dp[idx][f-'a'][l-'a'] = min(a,b);
    }

    int minimizeConcatenatedLength(vector<string>& words) {
        int n = words.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(26,vector<int>(26,-1)));
        return words[0].size() + helper(words, 1, n, words[0][0], words[0].back(), dp);
    }
};