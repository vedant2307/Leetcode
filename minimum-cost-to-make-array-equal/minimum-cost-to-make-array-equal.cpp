class Solution {
public:
    #define ll long long
    long long minCost(vector<int>& nums, vector<int>& cost) {
        ll left=1,right=1e6;
        ll ans; int n=nums.size();
        while(left<right){
            ll mid=left+(right-left)/2;
            ll cleft=0,cright=0;
            for(int i=0;i<n;i++){
                cleft+=(abs(nums[i]-mid)*((ll)cost[i]));
                cright+=(abs(nums[i]-(mid+1))*((ll)cost[i]));
            }
            ans=min(cleft,cright);
            if(cleft<cright) right=mid;
            else left=mid+1;
        }
        return ans;
    }
};