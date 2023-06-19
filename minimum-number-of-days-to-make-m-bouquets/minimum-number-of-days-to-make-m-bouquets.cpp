class Solution {
public:
bool check(int m,int k,vector<int>&nums,int mid){
      int tot=0,temp=0;
      for(auto it:nums){
          if(it<=mid){
              temp++;
              if(temp==k){
                  tot++; temp=0;
              }
          }
          else temp=0;
      }
      return tot>=m;
  }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if((long long)m*k>(long long)n) return -1;
      int low=*min_element(bloomDay.begin(),bloomDay.end());
      int high=*max_element(bloomDay.begin(),bloomDay.end());
      int ans=-1;
      while(low<=high){
          int mid=low+(high-low)/2;
          if(check(m,k,bloomDay,mid)) {
              ans=mid; high=mid-1;
          }
          else low=mid+1;
      }
      return ans;
    }
};