class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j;
        sort(nums.begin(),nums.end());
        for(j=0;j<n;j++){
            if(nums[j]-nums[i]>2*k) i++;
        }
        return j-i;
    }
};