class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans=0;
        double n=customers.size();
        double curr=0;
        for(double i=0;i<n;i++){
            if(curr<customers[i][0]) curr=customers[i][0];
            curr+=customers[i][1];
            ans+=(curr-customers[i][0]);
        }
        return ans/n;
    }
};