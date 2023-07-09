class Solution {
public:
    #define ll long long
    long long putMarbles(vector<int>& w, int k) {
        ll ans=0LL;
        int n=w.size();
        for(int i=0;i<n-1;i++) w[i]+=w[i+1];
        w.pop_back();
        sort(w.begin(),w.end());
        for(int i=0;i<k-1;i++) ans+= (ll)(w[n-i-2]-w[i]);
        return ans;
    }
};