class Solution {
public:
    int largestVariance(string s) {
        int n=s.length(),ans=0;
        unordered_set<char>st(begin(s),end(s));
        for(auto a:st){
            for(auto b:st){
                if(a==b) continue;
                for(int k=0;k<2;k++){
                    int cnt1=0,cnt2=0;
                    for(auto it:s){
                        if(it==a) cnt1++;
                        if(it==b) cnt2++;
                        if(cnt2>cnt1) cnt1=cnt2=0;
                        if(cnt1 && cnt2) ans=max(ans,cnt1-cnt2);
                    }
                    reverse(s.begin(),s.end());
                }
            }
        }
        return ans;
    }
};