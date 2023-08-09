class Solution {
public:
    bool check(vector<int>& nums, int p, int mid, int n){
        int i=0;
        while(i<n-1){
            int diff=nums[i+1]-nums[i];
            if(diff<=mid){
                p--; i++;
            }
            i++;
        }
        return p<=0;
    }
    int minimizeMax(vector<int>& nums, int p) {
        if(p==0) return 0;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int high=nums[n-1]-nums[0],low=high,ans=-1;
        for(int i=1;i<n;i++) low=min(low,nums[i]-nums[i-1]);
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(nums,p,mid,n)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};