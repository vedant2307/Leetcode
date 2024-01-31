class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size(),cnt=0,nextEnd=0,currEnd=0;

        for(int i=0;i<n-1;i++){
            nextEnd = max(nextEnd, nums[i]+i);
            if(i==currEnd){
                cnt++;
                currEnd=nextEnd;
            }
        }
        return cnt;
    }
};