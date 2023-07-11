class Solution {
public:
    vector<vector<int>>ans;
    void helper(vector<int>&nums, vector<int>&tmp, int t, int idx, int n){
        if(t==0){
            ans.push_back(tmp);
            return;    
        }
        for(int i=idx;i<n;i++){
            if(i>idx && nums[i]==nums[i-1]) continue;
            if(nums[i]<=t){
                tmp.push_back(nums[i]);
                helper(nums,tmp,t-nums[i],i+1,n);
                tmp.pop_back();
            }
            else break;
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>tmp;
        int n=candidates.size();
        helper(candidates,tmp,target,0,n);
        return ans;
    }
};