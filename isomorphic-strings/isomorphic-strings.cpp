class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.length(),m=t.length();
        if(n!=m) return false;
        unordered_map<char,char>mp;
        unordered_map<char,bool>mp1;
        for(int idx=0;idx<n;idx++){
            if(mp.find(s[idx])!=mp.end()){
                if(mp[s[idx]]!=t[idx]) return false;
            }
            else{
                if(mp1[t[idx]]) return false;
                mp[s[idx]]=t[idx];
                mp1[t[idx]]=true;
            }
        }
        return true;
    }
};