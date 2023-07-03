class Solution {
public:
    int helper(int m,vector<vector<int>>&nums,int idx,vector<int>&temp){
        if(idx==m){
            for(auto it:temp){
                if(it!=0) return -20;
            }
            return 0;
        }
        int from=nums[idx][0],to=nums[idx][1];
        temp[from]--; temp[to]++;
        int pick=helper(m,nums,idx+1,temp)+1;
        temp[from]++; temp[to]--;
        int npick=helper(m,nums,idx+1,temp);
        return max(pick,npick);
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int>temp(n);
        int m=requests.size();
        return helper(m,requests,0,temp);
    }
};