class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int cnt=0,n=points.size();
        sort(points.begin(),points.end());
        long temp=LONG_MIN;
        for(int i=0;i<n;i++){
            if(temp<points[i][0]){
                cnt++;
                temp=points[i][1];
            }
            else{
                if(points[i][1]<temp) temp=points[i][1];
            }
        }
        return cnt;
    }
};