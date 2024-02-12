class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans,cnt=0;
        for(auto it:nums){
            if(cnt==0) ans=it;
            if(it==ans) cnt++;
            else cnt--;
        }
        return ans;

    }
};