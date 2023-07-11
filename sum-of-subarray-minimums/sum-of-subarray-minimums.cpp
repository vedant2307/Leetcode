class Solution {
public:
    #define ll long long
    #define mod 1000000007
    int sumSubarrayMins(vector<int>& arr) {
        stack<int>st;
        st.push(-1);
        int ans=0,n=arr.size();
        for(int idx=0;idx<n;idx++){
            while(st.size()>1 && arr[st.top()]>=arr[idx]){
                int top=st.top(); st.pop();
                ll left=top-st.top(),right=idx-top;
                ll temp = (((arr[top]*left)%mod)*right)%mod;
                ans = (ans+(int)temp)%mod;
            }
            st.push(idx);
        }
        while(st.size()>1){
            int top=st.top(); st.pop();
            ll left=top-st.top(),right=n-top;
            ll temp = (((arr[top]*left)%mod)*right)%mod;
            ans = (ans+(int)temp)%mod;
        }
        return ans;
    }
};