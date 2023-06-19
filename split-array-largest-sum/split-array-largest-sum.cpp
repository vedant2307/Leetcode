class Solution {
public:
    bool check(vector<int>&nums,int k,int mid){
        int sum=0,cnt=1;
        for(auto it:nums){
            if(it>mid) return false;
            sum+=it;
            if(sum>mid){
                sum=it; cnt++;
            }
        }
        return cnt<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(nums,k ,mid)){
                ans=mid; high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};