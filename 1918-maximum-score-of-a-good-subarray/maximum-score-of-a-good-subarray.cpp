class Solution {
 
public:
    int maximumScore(vector<int>& arr, int k) {
        stack<int>st;
        st.push(-1);
        int ans=0,n=arr.size();
        for(int idx=0;idx<n;idx++){
            while(st.size()>1 && arr[st.top()]>=arr[idx]){
                int top=st.top(); st.pop();
                int left=top-st.top(),right=idx-top;
                if(k>st.top() && k<idx) ans=max(ans,(left+right-1)*arr[top]);
            }
            st.push(idx);
        }
        while(st.size()>1){
            int top=st.top(); st.pop();
            int left=top-st.top(),right=n-top;
            if(k>st.top() && k<n) ans=max(ans,(left+right-1)*arr[top]);
        }
        return ans;
    }
};