class Solution {
public:
    int beautySum(string s) {
        int n=s.size(),ans=0;
        for(int i=0;i<n;i++){
            unordered_map<char,int>fr;
            for(int j=i;j<n;j++){
                fr[s[j]]++;
                int maxi=0,mini=n+1;
                for(auto it:fr){
                    maxi=max(maxi,it.second); mini=min(mini,it.second);
                }
                ans+=(maxi-mini);
            }
        }
        return ans;
    }
};