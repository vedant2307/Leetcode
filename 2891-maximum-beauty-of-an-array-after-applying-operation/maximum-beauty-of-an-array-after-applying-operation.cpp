class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
       int n=nums.size();
       int t=1e5;
       int s=3*t+3;
       vector<int>temp(s,0);
       for(auto it:nums){
           int a=(it-k)+t,b=(it+k)+t;
           temp[a]++;
           temp[b+1]--;
       } 
       int ans=0,sum=0;
       for(int i=1;i<s;i++){
           sum+=temp[i];
           ans=max(ans,sum);
       }
       return ans;
    }
};