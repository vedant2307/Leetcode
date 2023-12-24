class Solution {
public:
    int mod = 1e9+7;
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        unordered_set<int>st;
        hFences.push_back(1); hFences.push_back(m);
        vFences.push_back(1); vFences.push_back(n);
        int l1=hFences.size(),l2=vFences.size();
        for(int i=0;i<l1;i++){
            for(int j=0;j<l1;j++){
                if(i!=j) st.insert(abs(hFences[i]-hFences[j]));
            }
        }
        long long ans=-1;
        for(int i=0;i<l2;i++){
            for(int j=0;j<l2;j++){
                long long val=abs(vFences[i]-vFences[j]);
                if(i!=j && st.find(val)!=st.end()) ans = max(ans,val);
            }
        }
        if(ans==-1) return ans;
        return (ans*ans)%mod;
    }
};