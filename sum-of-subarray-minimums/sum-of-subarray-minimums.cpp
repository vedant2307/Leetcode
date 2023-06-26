class Solution {
public:
    int mod=1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>prev(n),next(n);
        stack<int>st; 
        next[n-1]=1; st.push(n-1);
        for(int idx=n-2;idx>=0;idx--){
            while(!st.empty() && arr[st.top()]>=arr[idx]) st.pop();
            if(st.empty()){
                next[idx]=n-idx;
            }
            else next[idx]=st.top()-idx;
            st.push(idx);
        }

        while(!st.empty()) st.pop();

        prev[0]=1; st.push(0);
        for(int idx=1;idx<n;idx++){
            while(!st.empty() && arr[st.top()]>arr[idx]) st.pop();
            if(st.empty()){
                prev[idx]=idx+1;
            }
            else prev[idx]=idx-st.top();
            st.push(idx);
        }

        int ans=0;
        for(int i=0;i<n;i++){
            int cnt1=prev[i],cnt2=next[i];
            long long temp=(cnt1*cnt2)%mod;
            temp=(temp*arr[i])%mod;
            ans= (ans+temp)%mod;
        }

        return ans;
    }
};
