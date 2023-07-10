class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int goal) {
        int ans=0,sum=0;
        unordered_map<int,int>tmp;
        for(auto it:nums){
            sum+=(it%2);
            if(sum==goal) ans++;
            if(tmp[sum-goal]) ans+=tmp[sum-goal];
            tmp[sum]++;
        }
        return ans;
    }
};