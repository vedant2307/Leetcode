class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans=0,cnt=0;
        int i=0,n=size(nums);
        for(int j=0;j<n;j++){
            if(nums[j]%2){
                cnt=0;
                k--;
            }
            while(k==0){
                k+= (nums[i++]%2);
                cnt++;
            }
            ans+=cnt;
        }
        return ans;
    }
};