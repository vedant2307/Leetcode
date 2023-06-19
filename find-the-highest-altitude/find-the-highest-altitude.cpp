class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=0,sum=0;
        for(auto it:gain){
            sum+=it; ans=max(ans,sum);
        }
        return ans;
    }
};