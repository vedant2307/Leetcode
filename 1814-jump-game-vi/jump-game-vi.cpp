class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        vector<int>dp(size(nums));
        multiset<int>st({dp[0]=nums[0]});

        for(int idx=1;idx<size(nums);idx++){
            if(idx>k) st.erase(st.find(dp[idx-k-1]));
            st.insert({dp[idx]=*rbegin(st)+nums[idx]});
        }

        return dp.back();
    }
};