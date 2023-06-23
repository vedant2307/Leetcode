class Solution {
public:
    #define ll double
    int helper(string s,string t,int idx1,int idx2){
        if(idx2<0) return 1;
        if(idx1<0) return 0;
        if(s[idx1]==t[idx2]) return helper(s,t,idx1-1,idx2-1)+helper(s,t,idx1-1,idx2);
        return helper(s,t,idx1-1,idx2);
    }
    // return helper(s,t,n-1,m-1);
    int numDistinct(string s, string t) {
        int n=s.length(),m=t.length();
        vector<ll>prev(m+1);
        prev[0]=1LL;
    for(int idx1=1;idx1<=n;idx1++) {
        vector<ll>curr(m+1); curr[0]=1LL;
        for(int idx2=1;idx2<=m;idx2++){
            curr[idx2] = s[idx1-1]==t[idx2-1] ? prev[idx2-1]+prev[idx2]:prev[idx2];
      }
      prev=curr;
    }
      return (int)prev[m];    
    }
};