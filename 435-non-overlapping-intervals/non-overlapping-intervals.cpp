class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        int i=0,j=1,ans=0;
        while(j<n)
        {
            if(intervals[i][1]>intervals[j][0])
            {
                if(intervals[i][1]>intervals[j][1])
                    i=j;
                ans++;
            }
            else
                i=j; 
            j++; 
        }
        return ans;
    }
};