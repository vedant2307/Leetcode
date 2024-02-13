class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b){
        if(a[1]==b[1]) return a[0]>b[0];
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans=0;
        sort(intervals.begin(),intervals.end(),cmp);
        int curr_end=0;
        for(int it=1;it<size(intervals);it++){
            if(intervals[curr_end][1]<=intervals[it][0]) curr_end=it;
            else ans++;
        }
        return ans;
    }
};