class Solution {
public:
    int firstUniqChar(string s) {
        // vector<int>mp(26);
        unordered_map<char,int>mp;
        for(auto it:s) mp[it]++;
        for(int i=0;i<s.size();i++) if(mp[s[i]]==1) return i;
        return -1; 
    }
};