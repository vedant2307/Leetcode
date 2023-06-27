class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int>q; vector<int>ans;
        int i=0,j=0;
        while(j<n){
            while(!q.empty() && nums[j]>q.back()) q.pop_back();
            q.push_back(nums[j]);
            if(j>=k-1){
                ans.push_back(q.front());
                if(nums[i]==q.front()) q.pop_front();
                i++;
            }
            j++;
        }
        return ans;
    }
};