class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b){
        if(a[0]==b[0]) return a[1]>b[1];
        return a[0]<b[0];
    }

    int numberOfPairs(vector<vector<int>>& points) {
        int ans=0;
        int n=points.size();
        sort(points.begin(),points.end(),cmp);
        for(int i=0;i<n;i++){
            int y1=points[i][1];
            int maxi=INT_MIN,mini=INT_MAX;
            for(int j=i+1;j<n;j++){
                int y2=points[j][1];
                if(y1>=y2){
                    if(j-i==1){
                        ans++;
                    }
                    else if(mini>y1 && maxi<y2) ans++;
                }
                if(y2>y1) mini=min(mini,y2);
                else maxi=max(maxi,y2);
            }
        }
        
        return ans;
    }
};