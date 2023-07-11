class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
        int n=nums.size();
        vector<int>ans(n);
        for(int idx=n-1;idx>=0;idx--){
            while(!st.empty() && st.top()<=nums[idx]) st.pop();
            st.push(nums[idx]);
        }
        for(int idx=n-1;idx>=0;idx--){
            while(!st.empty() && st.top()<=nums[idx]) st.pop();
            if(st.empty()) ans[idx]=-1;
            else ans[idx]=st.top();
            st.push(nums[idx]);
        }
        return ans;
    }
};