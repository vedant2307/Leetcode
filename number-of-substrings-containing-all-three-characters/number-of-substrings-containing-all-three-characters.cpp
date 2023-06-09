class Solution {
public:
    int numberOfSubstrings(string s) {
        int i=0,j=0,ans=0,cnt=3,n=s.length();
        unordered_map<char,int>mp;
        while(j<n){
            if(mp[s[j++]]++==0) cnt--;
            int len=(n-j);
            while(cnt==0){
                if(--mp[s[i++]]==0) cnt++;
                ans+=(len+1);
            }
        }
        return ans;
    }
};