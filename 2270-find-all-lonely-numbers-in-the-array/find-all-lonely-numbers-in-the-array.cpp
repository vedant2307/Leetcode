class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(auto it:nums) mp[it]++;
        for(auto it:nums){
            if(mp[it]==1 && (!mp[it-1] && !mp[it+1]) ) ans.push_back(it);
        }
        return ans;
    }
};