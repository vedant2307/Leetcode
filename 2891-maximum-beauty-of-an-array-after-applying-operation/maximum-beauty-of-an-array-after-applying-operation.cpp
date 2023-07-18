class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
       int n=nums.size();
       int t=1e5;
       int s=3*t+3;
       int mini=1e9,maxi=-1e9;
       vector<int>temp(s,0);
       for(auto it:nums){
           int a=(it-k)+t,b=(it+k)+t;
           temp[a]++;
           temp[b+1]--;
           mini=min(mini,a);
           maxi=max(maxi,b);
       } 
       int ans=0,sum=0;
       for(int i=mini;i<=maxi;i++){
           sum+=temp[i];
           ans=max(ans,sum);
       }
       return ans;
    }
};