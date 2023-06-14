class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        int idx_pos=0,idx_neg=1;
        for(auto it:nums){
            if(it<0){
                ans[idx_neg]=it; idx_neg+=2;
            }
            else{
                ans[idx_pos]=it; idx_pos+=2;
            }
        }
        return ans;
    }
};