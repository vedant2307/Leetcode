class Solution {
public:
    string minWindow(string s, string t) {
        int i=0,j=0,n=s.length();
        string ans; int mini=n+1;
        unordered_map<char,int>mp;
        for(auto it:t) mp[it]++;
        int cnt=mp.size();
        while(j<n){
            while(j<n && cnt>0){
                if(mp.find(s[j])!=mp.end()){
                    mp[s[j]]--;
                    if(mp[s[j]]==0) cnt--;
                } 
                j++;
            }
            while(cnt==0){
                if(mp.find(s[i])!=mp.end()){
                    if(mp[s[i]]==0){
                        int t=(j-i);
                        if(t<mini){
                            ans=s.substr(i,t); mini=t;
                        }
                        cnt++;
                    }
                    mp[s[i]]++;
                }
                i++;
            }
        }
        return ans;
    }
};