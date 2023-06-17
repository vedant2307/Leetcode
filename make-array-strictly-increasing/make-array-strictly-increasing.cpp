class Solution {
public:
    map<pair<int,int>,int>mp;
    int helper(vector<int>&arr1,vector<int>&arr2,int prev,int idx,int up,int n,int m){
        if(idx==m) return 0;
        if(mp.count({idx,prev})) return mp[{idx,prev}];
        up=upper_bound(arr2.begin()+up,arr2.end(),prev)-arr2.begin();
        int pick=2001,npick=2001;
        if(arr1[idx]>prev) npick=helper(arr1,arr2,arr1[idx],idx+1,up,n,m);
        if(up<n) pick=helper(arr1,arr2,arr2[up],idx+1,up,n,m)+1;
        return mp[{idx,prev}]=min(npick,pick);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int n=arr2.size(),m=arr1.size();
        sort(arr2.begin(),arr2.end());
        int ans=helper(arr1,arr2,-1,0,0,n,m);
        return ans>=2001 ? -1 : ans;
    }
};