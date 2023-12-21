class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int ans=0,n=points.size();
        for(int i=0;i<n-1;i++) ans = max(ans, points[i+1][0]-points[i][0]);
        return ans;
    }
};