class Solution {
public:
    int maxScore(string s) {
        int os=0,zs=0;
        for(auto it:s){
            if(it=='1') os++;
        }
        int ans=0,n=s.length();
        for(int i=0;i<n-1;i++){
            if(s[i]=='1') os--;
            else zs++;
            ans=max(ans,os+zs);
        }
        int temp = s[0]=='0' ? 1+os : os-1;
        ans=max(ans,temp);
        return ans;
    }
};