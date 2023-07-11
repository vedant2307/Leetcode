class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        stack<int>st;
        st.push(-1);
        int ans=0;
        int n=arr.size();
        for(int idx=0;idx<n;idx++){
            while(st.size()>1 && arr[st.top()]>arr[idx]){
                int top=st.top(); st.pop();
                int left=top-st.top(),right=idx-top;
                int temp = (left+right-1)*arr[top];
                ans = max(ans,temp);
            }
            st.push(idx);
        }
        while(st.size()>1){
            int top=st.top(); st.pop();
            int left=top-st.top(),right=n-top;
            int temp = (left+right-1)*arr[top];
            ans = max(ans,temp);
        }
        return ans;
    }
};