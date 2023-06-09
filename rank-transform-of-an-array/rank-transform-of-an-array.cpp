class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int>mp;
        for(auto it:arr) mp[it]++;
        int rank=0,n=arr.size();
        for(auto it:mp) mp[it.first]=++rank;
        for(int i=0;i<n;i++) arr[i]=mp[arr[i]];
        return arr;
    }
};