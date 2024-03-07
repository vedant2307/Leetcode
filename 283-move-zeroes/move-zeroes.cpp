class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size(),j=0,i;
        for(i=0;i<n && j<n;){
            while(j<n && nums[j]==0) j++;
            if(j<n) nums[i++]=nums[j++];
        }
        while(i<n) nums[i++]=0;
        return;
    }
};