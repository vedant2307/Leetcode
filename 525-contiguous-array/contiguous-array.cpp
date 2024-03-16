class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int ans=0,sum=0;
        for(int i=0;i<n;i++){
            sum+= (nums[i]==0 ? -1:1); cout<<sum<<endl;
            if(sum==0) ans=i+1;
            if(mp.find(sum)==mp.end()) mp[sum]=i;
            else ans=max(ans,i-mp[sum]);
        }
        return ans;
    }
};