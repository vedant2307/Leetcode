class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto it:nums) mp[it]++;
        int ans=0;
        for(auto it:mp){
            int f=it.second;
            ans+= (f*(f-1))/2;
        }
        return ans;
    }
};