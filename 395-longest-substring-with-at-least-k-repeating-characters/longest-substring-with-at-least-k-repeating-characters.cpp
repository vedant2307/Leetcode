class Solution {
public:
    int longestSubstring(string s, int k) {
        int ans=0,n=s.size();
        for(int i=0;i<n;i++){
            vector<int>check(26);
            int cnt=0;
            for(int j=i;j<n;j++){
                check[s[j]-'a']++;
                if(check[s[j]-'a']==1) cnt++;
                if(check[s[j]-'a']==k) cnt--;
                if(cnt==0) ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};