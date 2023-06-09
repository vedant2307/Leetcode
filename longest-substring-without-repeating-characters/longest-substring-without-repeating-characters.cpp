class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        int i=0,j=0,n=s.length();
        unordered_map<char,int>mp;
        while(j<n){
            while(j<n && mp[s[j]]==0){
                mp[s[j]]++; j++;
            }
            ans=max(ans,j-i);
            while(mp[s[j]]){
                mp[s[i]]--; i++;
            }
        }
        return ans;
    }
};