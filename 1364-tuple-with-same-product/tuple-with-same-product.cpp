class Solution {
public:
    int helper(int num){
        return (num*(num-1))/2;
    }
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int mul=nums[i]*nums[j];
                mp[mul]++;
            }
        }
        int ans=0;
        for(auto it:mp){
            int f=it.second;
            if(f>1){
                int a=helper(f);
                ans=ans+(8*a);
            }
        }
        return ans;
    }
};