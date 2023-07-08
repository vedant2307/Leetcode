class Solution {
public:
    #define ll long long
    long long putMarbles(vector<int>& weights, int k) 
    {
        ll ans = 0LL;
        int n=weights.size();
        for(int i=0;i<weights.size()-1;i++)
            weights[i] += weights[i+1];
        weights.pop_back();
        sort(weights.begin(),weights.end());
        for(int i=0;i<k-1;i++)
            ans+=weights[n-i-2]-weights[i];
        return ans;
    }
};