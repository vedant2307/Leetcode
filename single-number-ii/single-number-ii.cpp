class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0,n=nums.size();
        for(int i=0;i<32;i++){
            int sum=0;
            for(int j=0;j<n;j++){
                if((nums[j]>>i) & 1){
                    sum++;
                    sum%=3;
                }
            }
            if(sum) ans |= (sum<<i);
        }
        return ans;
    }
};