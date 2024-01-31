class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        vector<int>dp(size(nums));
        deque<int>q{0};
        dp[0]=nums[0];

        for(int idx=1;idx<size(nums);idx++){
            if(q.front()<idx-k) q.pop_front();
            dp[idx] = dp[q.front()]+nums[idx];
            while(!q.empty() && dp[q.back()]<=dp[idx]) q.pop_back();
            q.push_back(idx);
        }

        return dp.back();
    }
};