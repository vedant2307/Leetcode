class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0, start=-1;
        vector<int>mp(256,-1);
        for(int i=0;i<s.length();i++){
            if(mp[s[i]]>start) start=mp[s[i]];
            mp[s[i]]=i;
            ans=max(ans,i-start);
        }
        return ans;
    }
};