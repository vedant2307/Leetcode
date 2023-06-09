class Solution {
public:
    int totalFruit(vector<int>& s) {
        int i=0,j=0,n=s.size();
        int cnt=2,ans=0;
        unordered_map<int,int>mp;
        while(j<n){
            while(j<n && (cnt>0 || (cnt==0 && mp[s[j]]))){
                if(mp[s[j]]==0) cnt--; 
                mp[s[j]]++; j++;
            }
            ans=max(ans,j-i);
            while(cnt==0){
                mp[s[i]]--;
                if(mp[s[i]]==0) cnt++;
                i++;
            }
        }
        return ans;
    }
};