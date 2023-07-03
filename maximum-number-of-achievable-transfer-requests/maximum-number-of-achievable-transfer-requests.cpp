class Solution {
public:
    int helper(int n,vector<vector<int>>&nums,int idx,vector<int>&temp){
        if(idx==nums.size()){
            for(auto it:temp){
                if(it!=0) return INT_MIN;
            }
            return 0;
        }
        temp[nums[idx][0]]--; temp[nums[idx][1]]++;
        int pick=helper(n,nums,idx+1,temp)+1;
        temp[nums[idx][0]]++; temp[nums[idx][1]]--;
        int npick=helper(n,nums,idx+1,temp);
        return max(pick,npick);
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int>temp(n);
        return helper(n,requests,0,temp);
    }
};