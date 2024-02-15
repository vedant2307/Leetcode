class Solution {
public:
    #define ll long long 
    long long largestPerimeter(vector<int>& nums) {
        ll ans=0LL;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<ll>prefix(n,0LL);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1] + nums[i];
        }
        for(int idx=n-1;idx>=2;idx--){
            if(prefix[idx-1]>nums[idx]) return prefix[idx];
        }
        return -1;
    }
};