class Solution {
public:
    int numberOfSubstrings(string s) {
        int i=0,j=0,n=s.length();
        unordered_map<char,int>mp;
        int ans=0;
        int cnt=3;
        while(j<n){
            while(j<n && cnt>0){
                if(mp[s[j]]==0) cnt--;
                mp[s[j]]++;
                j++;
            }
            int len=(n-j);
            while(cnt==0){
                mp[s[i]]--;
                ans+=(len+1);
                if(mp[s[i]]==0) cnt++;
                i++;
            }
        }
        return ans;
    }
};