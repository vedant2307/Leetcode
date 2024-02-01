class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& arr) {
        unordered_map<int,int>ans;
        stack<int>st;
        int n=arr.size();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[i]>arr[st.top()]) st.pop();
            if(st.empty()) ans[arr[i]]=-1;
            else ans[arr[i]] = arr[st.top()];
            st.push(i);
        }
        vector<int>ans1;
        for(auto it:nums1) ans1.push_back(ans[it]);

        return ans1;
    }
};